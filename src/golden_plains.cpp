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

Model GraphicsLayer::createModel(std::string modelPath, Texture texture_id, glm::vec3 pos){
	vulkHandler.loadModel(id_counter, modelPath, texture_id, pos);
	return id_counter++;
}

Model GraphicsLayer::duplicateModel(Model original_model_id){
	vulkHandler.duplicateModel(id_counter, original_model_id);
	return id_counter++;
}

void GraphicsLayer::destroyModel(Model model_id){
	vulkHandler.queueDestroyModel(model_id);
}

void GraphicsLayer::destroyTexture(Texture texture_id) {
	vulkHandler.destroyTexture(texture_id);
}

void GraphicsLayer::setModelPosition(Model model_id, glm::vec3 pos){
	vulkHandler.setModelPosition(model_id, pos);
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

TextBox GraphicsLayer::createTextBox(std::string text, double x, double y, double width, double height){
	std::vector<uint32_t> textChars;
	double x_offset = 0.0;
	for(char ch : text){
		uint32_t char_id = createChar(ch, x + x_offset, y);
		x_offset-=0.6;
		textChars.push_back(char_id);
	}
	textBoxes.insert(std::make_pair(id_counter, textChars));
	return id_counter++;
}

uint32_t GraphicsLayer::createChar(char character, double x, double y){
	vulkHandler.createGlyph(id_counter, font, x, y, fontUVCoords.at(character).first, fontUVCoords.at(character).second, font_u_offset, font_v_offset);
	return id_counter++;
}

Texture GraphicsLayer::createTexture(std::string texturePath){
	vulkHandler.loadTexture(id_counter, texturePath);
	return id_counter++;
}

void GraphicsLayer::setTextureForModel(Texture texture_id, Model model_id){
	vulkHandler.setTextureForModel(texture_id, model_id);
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