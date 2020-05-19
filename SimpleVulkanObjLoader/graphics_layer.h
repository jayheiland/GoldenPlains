#ifndef GRAPHICS_LAYER_H
#define GRAPHICS_LAYER_H

#include "vulkan_handler.h"

class GraphicsLayer
{
private:
	VulkanHandler vulkHandler;
public:
	void init();
	void draw();
	bool windowShouldClose();
	void cleanup();
	
};

#endif