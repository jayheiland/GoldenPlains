#include "graphics_layer.h"

GraphicsLayer::GraphicsLayer()
{
	id_counter = 0;
}

void GraphicsLayer::init(std::string vertShdrPath, std::string fragShdrPath)
{
	try {
		vulkHandler.initWindow();
		vulkHandler.initVulkan(vertShdrPath, fragShdrPath);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

Model_ID GraphicsLayer::loadModel(std::string modelPath, Texture_ID texture_id)
{
	vulkHandler.loadModel(id_counter, modelPath, texture_id);
	return id_counter++;
}

Texture_ID GraphicsLayer::loadTexture(std::string texturePath)
{
	vulkHandler.loadTexture(id_counter, texturePath);
	return id_counter++;
}

void GraphicsLayer::setTextureForModel(Texture_ID texture_id, Model_ID model_id)
{
	vulkHandler.setTextureForModel(texture_id, model_id);
}

void GraphicsLayer::draw()
{
	try {
		vulkHandler.draw();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

bool GraphicsLayer::windowShouldClose()
{
	if (vulkHandler.windowCloseButtonClicked()) {
		return true;
	}
	return false;
}


void GraphicsLayer::cleanup()
{
	try {
		vulkHandler.cleanup();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}