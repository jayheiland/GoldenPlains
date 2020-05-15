#pragma once

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

