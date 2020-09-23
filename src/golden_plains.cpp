#include "golden_plains.h"

GraphicsLayer::GraphicsLayer(std::string vertShdrPath, std::string fragShdrPath){
	id_counter = 0;
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

void GraphicsLayer::loadCharTextures(std::string directory){
	std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(char ch : chars){
		std::stringstream ss;
		ss << directory << ch << ".png";
		Texture tx = createTexture(ss.str());
		charTextures.insert(std::make_pair(ch, tx));
	}
}

TextBox GraphicsLayer::createTextBox(std::string text, int x, int y){
	std::vector<uint32_t> textChars;
	int x_offset = 0;
	for(char ch : text){
		uint32_t char_id = createChar(ch, x + x_offset, y);
		x_offset+=0.1;
		textChars.push_back(char_id);
	}
	textBoxes.insert(std::make_pair(id_counter, textChars));
	return id_counter++;
}

uint32_t GraphicsLayer::createChar(char character, int x, int y){
	vulkHandler.createGlyph(id_counter, charTextures.at(character), x, y);
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