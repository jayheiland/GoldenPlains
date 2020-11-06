#include "golden_plains.h"

GraphicsLayer::GraphicsLayer(std::string vertShdrPath, std::string fragShdrPath){
	id_counter = 1;
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

GraphObjID GraphicsLayer::createChar(char character, double x, double y, uint pixWidth, uint pixHeight){
	vulkHandler.createGlyph(id_counter, font, x, y, fontUVCoords.at(character).first, fontUVCoords.at(character).second, font_u_offset, font_v_offset, pixWidth, pixHeight, glm::vec3(1.0f, 1.0f, 1.0f));
	return id_counter++;
}

bool GraphicsLayer::mouseIsInside(Rect rect){
	mousePosY = (double)vulkHandler.getScreenDimensions().second - mousePosY;
	return (mousePosX >= rect.x && mousePosX <= rect.x+rect.w && mousePosY >= rect.y && mousePosY <= rect.y+rect.h);
}

void GraphicsLayer::handleInteractions(){
	int lmb = vulkHandler.getMouseButton(GLFW_MOUSE_BUTTON_LEFT);
	int rmb = vulkHandler.getMouseButton(GLFW_MOUSE_BUTTON_RIGHT);

	if(lmb == GLFW_PRESS && lmbPrevState != GLFW_PRESS){
		for(auto button : buttons){
			if(mouseIsInside(textBoxes[button.second.textbox].rect)){
				button.second.onLeftClick(button.first);
			}
		}
	}
	lmbPrevState = lmb;
	rmbPrevState = rmb;
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

GraphObjID GraphicsLayer::createTextBox(std::string text, double x, double y, uint width, uint height){
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
	textbox.rect.x = x;
	textbox.rect.y = y;
	textbox.rect.w = width;
	textbox.rect.h = height;
	textBoxes[id_counter] = textbox;
	return id_counter++;
}

GraphObjID GraphicsLayer::createButton(void (*onLeftClick)(GraphObjID), std::string text, double x, double y, uint width, uint height){
	Button button;
	button.textbox = createTextBox(text, x, y, width, height);
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