#include "golden_plains.h"

const int NUMDIM =3;
const int RIGHT =0;
const int LEFT =1;
const int MIDDLE =2;

GraphicsLayer::GraphicsLayer(std::string vertShdrPath, std::string fragShdrPath){
	id_counter = 1;
	nearestHit_LeftClick = 0;
	font_u_offset = 0.03794;
	font_v_offset = 0.33;
	try {
		vulkHandler.initWindow();
		vulkHandler.initVulkan(vertShdrPath, fragShdrPath);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void GraphicsLayer::setKeyEventCallback(void (*onKeyPress)(GLFWwindow*,int,int,int,int)){
	vulkHandler.setKeyEventCallback(onKeyPress);
}

GraphObjID GraphicsLayer::createChar(char character, double x, double y, uint pixWidth, uint pixHeight){
	vulkHandler.createGlyph(id_counter, font, x, y, fontUVCoords.at(character).first, fontUVCoords.at(character).second, font_u_offset, font_v_offset, pixWidth, pixHeight, glm::vec3(1.0f, 1.0f, 1.0f));
	return id_counter++;
}

bool GraphicsLayer::mouseInRect(Rect rect){
	double modMousePosY = (double)vulkHandler.getScreenDimensions().second - mousePosY;
	return (mousePosX >= rect.x && mousePosX <= rect.x+rect.w && modMousePosY >= rect.y && modMousePosY <= rect.y+rect.h);
}

bool HitBoundingBox(double minB[NUMDIM], double maxB[NUMDIM]/*box */, double origin[NUMDIM], double dir[NUMDIM]/*ray */, double *coord/* hit point */)
{
	/* 
	Fast Ray-Box Intersection
	by Andrew Woo
	from "Graphics Gems", Academic Press, 1990
	*/
	bool inside = true;
	char quadrant[NUMDIM];
	int i;
	int whichPlane;
	double maxT[NUMDIM];
	double candidatePlane[NUMDIM];

	/* Find candidate planes; this loop can be avoided if
   	rays cast all from the eye(assume perpsective view) */
	for (i=0; i<NUMDIM; i++)
		if(origin[i] < minB[i]) {
			quadrant[i] = LEFT;
			candidatePlane[i] = minB[i];
			inside = false;
		}else if (origin[i] > maxB[i]) {
			quadrant[i] = RIGHT;
			candidatePlane[i] = maxB[i];
			inside = false;
		}else	{
			quadrant[i] = MIDDLE;
		}

	/* Ray origin inside bounding box */
	if(inside)	{
		coord = origin;
		return (true);
	}


	/* Calculate T distances to candidate planes */
	for (i = 0; i < NUMDIM; i++)
		if (quadrant[i] != MIDDLE && dir[i] !=0.)
			maxT[i] = (candidatePlane[i]-origin[i]) / dir[i];
		else
			maxT[i] = -1.;

	/* Get largest of the maxT's for final choice of intersection */
	whichPlane = 0;
	for (i = 1; i < NUMDIM; i++)
		if (maxT[whichPlane] < maxT[i])
			whichPlane = i;

	/* Check final candidate actually inside box */
	if (maxT[whichPlane] < 0.) return (false);
	for (i = 0; i < NUMDIM; i++)
		if (whichPlane != i) {
			coord[i] = origin[i] + maxT[whichPlane] *dir[i];
			if (coord[i] < minB[i] || coord[i] > maxB[i])
				return (false);
		} else {
			coord[i] = candidatePlane[i];
		}
	return (true);				/* ray hits box */
}

GraphObjID GraphicsLayer::mousePick_getNearestHit(){
	std::cout << "Entered mousePick_getNearestHit" << std::endl;

	std::pair<uint32_t, uint32_t> dimens = vulkHandler.getScreenDimensions();
	float x = (2.0f * mousePosX) / dimens.first - 1.0f;
	float y = 1.0f - (2.0f * mousePosY) / dimens.second;
	float z = 1.0f;
	glm::vec3 ray_normal_device_space = glm::vec3(x, y, z); 
	glm::vec4 ray_clip = glm::vec4(ray_normal_device_space.x, ray_normal_device_space.y, -1.0, 1.0);
	glm::vec4 ray_eye = glm::inverse(vulkHandler.getProjectionMatrix()) * ray_clip;
	ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0, 0.0);
	glm::vec3 ray_world = glm::vec3(glm::inverse(vulkHandler.getViewMatrix()) * ray_eye);
	ray_world = glm::normalize(ray_world);

	GraphObjID nearestBox = 0;
	double leastDist = DBL_MAX;
	for(auto box : boundingBoxes){
		double minBound[NUMDIM] = {box.second.minBound.x, box.second.minBound.y, box.second.minBound.z};
		double maxBound[NUMDIM] = {box.second.maxBound.x, box.second.maxBound.y, box.second.maxBound.z};
		glm::vec3 eye = vulkHandler.getCameraPosition();
		double origin[NUMDIM] = {eye.x, eye.y, eye.z};
		double dir[NUMDIM] = {ray_world.x, ray_world.y, ray_world.z};
		double coord[NUMDIM];
		if(HitBoundingBox(minBound, maxBound, origin, dir, coord)){
			std::cout << "Hit a bounding box! Box has minBound: " << box.second.minBound.x << "," << box.second.minBound.y << "," << box.second.minBound.z << " and maxBound: " << box.second.maxBound.x << "," << box.second.maxBound.y << "," << box.second.maxBound.z << std::endl;
			double cubedDist = std::abs((std::pow(coord[0]-origin[0], 3) + std::pow(coord[1]-origin[1], 3) + std::pow(coord[2]-origin[2], 3)));
			std::cout << "Found dist of: " << cubedDist << std::endl;
			if(cubedDist < leastDist){
				nearestBox = box.first;
				leastDist = cubedDist;
				std::cout << "New closest box is: " << nearestBox << std::endl;
			}
		}
	}
	return nearestBox;
}

void GraphicsLayer::handleInteractions(){
	int lmb = vulkHandler.getMouseButtonState(GLFW_MOUSE_BUTTON_LEFT);
	int rmb = vulkHandler.getMouseButtonState(GLFW_MOUSE_BUTTON_RIGHT);

	if(lmb == GLFW_PRESS && lmbPrevState != GLFW_PRESS){
		//handle GUI element intersections
		for(auto button : buttons){
			if(mouseInRect(textBoxes[button.second.textbox].rect)){
				Rect r = textBoxes[button.second.textbox].rect;
				button.second.onLeftClick(button.first);
			}
		}
		//handle 3D bounding box intersections
		nearestHit_LeftClick = mousePick_getNearestHit();
		std::cout << "Set nearestHit_LeftClick to :" << nearestHit_LeftClick << std::endl;
	}
	lmbPrevState = lmb;
	rmbPrevState = rmb;
}

void GraphicsLayer::debugLog(std::string msg){
	std::cout << "GoldenPlains: " << msg << std::endl;
}

GraphObjID GraphicsLayer::createModel(std::string modelPath, TextureID texture_id, glm::vec3 pos){
	vulkHandler.loadModel(id_counter, modelPath, texture_id, pos);
	return id_counter++;
}

GraphObjID GraphicsLayer::duplicateModel(GraphObjID original){
	vulkHandler.duplicateModel(id_counter, original);
	return id_counter++;
}

void GraphicsLayer::destroyModel(GraphObjID model){
	vulkHandler.queueDestroyModel(model);
}

void GraphicsLayer::destroyTexture(TextureID texture_id) {
	vulkHandler.destroyTexture(texture_id);
}

void GraphicsLayer::setModelPosition(GraphObjID model, glm::vec3 pos){
	vulkHandler.setModelPosition(model, pos);
}

void GraphicsLayer::setCamera(glm::vec3 cameraPos, glm::vec3 targetPos){
	vulkHandler.setCamera(cameraPos, targetPos);
}

void GraphicsLayer::loadFont(std::string path){
	std::string line1 = "abcdefghijklmnopqrstuvwxyz";
	std::string line2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string line3 = "0123456789.:,;'\"(!?)+-*/= ";
	double u = -0.0005;
	for(char ch : line1){
		fontUVCoords[ch] = std::make_pair(u, 0.0);
		u+=font_u_offset;
	}
	u=0.0;
	for(char ch : line2){
		fontUVCoords[ch] = std::make_pair(u, font_v_offset);
		u+=font_u_offset;
	}
	u=0.0;
	for(char ch : line3){
		fontUVCoords[ch] = std::make_pair(u, font_v_offset*2.0);
		u+=font_u_offset;
	}
	font = createTexture(path);
}

std::pair<uint, uint> GraphicsLayer::getScreenDimensions(){
	return vulkHandler.getScreenDimensions();
}

GraphObjID GraphicsLayer::getLeftClickedBoundingBox(){
	GraphObjID result = nearestHit_LeftClick;
	nearestHit_LeftClick = 0;
	return result;
}

GraphObjID GraphicsLayer::createTextBox(std::string text, double x, double y){
	TextBox textbox;
	std::vector<GraphObjID> textChars;
	uint charPixWidth = 10;
	uint charPixHeight = charPixWidth*2;
	double x_offset = 0.0;
	double x_offset_incr = (float)charPixWidth/vulkHandler.getScreenDimensions().first;
	for(char ch : text){
		GraphObjID char_id = createChar(ch, x + x_offset, y, charPixWidth, charPixHeight);
		x_offset+=x_offset_incr;
		textChars.push_back(char_id);
	}
	textbox.char_models.insert(textbox.char_models.begin(), textChars.begin(), textChars.end());
	auto dimen = vulkHandler.getScreenDimensions();
	textbox.rect.x = x*dimen.first;
	textbox.rect.y = y*dimen.second;
	textbox.rect.w = (int)text.length() * charPixWidth;
	textbox.rect.h = charPixHeight;
	textBoxes[id_counter] = textbox;
	return id_counter++;
}

GraphObjID GraphicsLayer::createButton(void (*onLeftClick)(GraphObjID), std::string text, double x, double y){
	Button button;
	button.textbox = createTextBox(text, x, y);
	button.sprite = GUI_NULL_ID;
	button.onLeftClick = onLeftClick;
	buttons[id_counter] = button;
	return id_counter++;
}

GraphObjID GraphicsLayer::createSprite(TextureID texture_id,  double x, double y, uint width, uint height){
	Sprite sprite;
	sprite.rect.x = x;
	sprite.rect.y = y;
	sprite.rect.w = width;
	sprite.rect.h = height;
	sprite.model = id_counter;
	vulkHandler.createGlyph(id_counter++, texture_id, x, y, 0, 0, 1, 1, width, height, glm::vec3(1.0f, 1.0f, 1.0f));
	sprites[id_counter] = sprite;
	return id_counter++;
}

TextureID GraphicsLayer::createTexture(std::string texturePath){
	vulkHandler.loadTexture(id_counter, texturePath);
	return id_counter++;
}

GraphObjID GraphicsLayer::createBoundingBox(glm::vec3 minBound, glm::vec3 maxBound){
	BoundingBox box;
	box.minBound = minBound;
	box.maxBound = maxBound;
	boundingBoxes[id_counter] = box;
	return id_counter++;
}

void GraphicsLayer::setTextureForModel(TextureID texture_id, GraphObjID model){
	vulkHandler.setTextureForModel(texture_id, model);
}

void GraphicsLayer::remove3DModel(GraphObjID id){
	vulkHandler.queueDestroyModel(id);
}

void GraphicsLayer::removeTextBox(GraphObjID id){
	for(auto textbox : textBoxes){
		if(textbox.first == id){
			for(auto charModel : textbox.second.char_models){
				remove3DModel(charModel);
			}
			textBoxes.erase(textbox.first);
			return;
		}
	}
}

void GraphicsLayer::removeButton(GraphObjID id){
	for(auto button : buttons){
		if(button.first == id){
			if(button.second.textbox != GUI_NULL_ID){
				removeTextBox(button.second.textbox);
			}
			if(button.second.sprite != GUI_NULL_ID){
				removeSprite(button.second.sprite);
			}
		}
	}
}

void GraphicsLayer::removeSprite(GraphObjID id){
	for(auto sprite : sprites){
		if(sprite.first == id){
			remove3DModel(sprite.first);
			sprites.erase(sprite.first);
			return;
		}
	}
}

void GraphicsLayer::draw(){
	try {
		vulkHandler.getMousePos(&mousePosX, &mousePosY);
		handleInteractions();
		vulkHandler.draw();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

bool GraphicsLayer::windowShouldClose(){
	if (vulkHandler.windowCloseButtonClicked()) {
		return true;
	}
	return false;
}


void GraphicsLayer::cleanup(){
	try {
		vulkHandler.cleanup();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}