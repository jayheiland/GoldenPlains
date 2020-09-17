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