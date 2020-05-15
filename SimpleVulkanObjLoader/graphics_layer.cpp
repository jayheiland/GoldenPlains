#include "graphics_layer.h"

void GraphicsLayer::init()
{
	try {
		vulkHandler.initWindow();
		vulkHandler.initVulkan();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
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