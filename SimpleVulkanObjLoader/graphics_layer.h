#ifndef GRAPHICS_LAYER_H
#define GRAPHICS_LAYER_H

#include <string>

#include "vulkan_handler.h"

class GraphicsLayer
{
private:
	VulkanHandler vulkHandler;
public:
	void init(std::string vertShdrPath, std::string fragShdrPath);
	void draw();
	bool windowShouldClose();
	void cleanup();
	
};

#endif