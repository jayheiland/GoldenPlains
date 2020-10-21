#include "golden_plains.h"

GraphicsLayer::GraphicsLayer(std::string vertShdrPath, std::string fragShdrPath){
	id_counter = 0;
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
	std::vector<uint32_t> textChars;
	int charPixWidth = 10;
	int charPixHeight = 20;
	double x_offset = 0.0;
	double x_offset_incr = (float)charPixWidth/vulkHandler.getScreenDimensions().first;
	for(char ch : text){
		std::cout << "x_offset: " << x_offset << std::endl;
		uint32_t char_id = createChar(ch, x + x_offset, y, charPixWidth, charPixHeight);
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

uint32_t GraphicsLayer::createChar(char character, double x, double y, int pixWidth, int pixHeight){
	vulkHandler.createGlyph(id_counter, font, x, y, fontUVCoords.at(character).first, fontUVCoords.at(character).second, font_u_offset, font_v_offset, pixWidth, pixHeight);
	return id_counter++;
}

TextureID GraphicsLayer::createTexture(std::string texturePath){
	vulkHandler.loadTexture(id_counter, texturePath);
	return id_counter++;
}

void GraphicsLayer::setTextureForModel(TextureID texture_id, GraphObjID model){
	vulkHandler.setTextureForModel(texture_id, model);
}

void GraphicsLayer::remove(GraphObjID id){

}

void GraphicsLayer::draw(){
	try {
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