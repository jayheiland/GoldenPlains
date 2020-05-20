#ifndef GRAPHICS_LAYER_H
#define GRAPHICS_LAYER_H

#include <string>

#include "vulkan_handler.h"

typedef uint32_t Model_ID;
typedef uint32_t Texture_ID;

class GraphicsLayer
{
private:
	VulkanHandler vulkHandler;
	uint32_t id_counter;
public:
	GraphicsLayer();
	void init(std::string vertShdrPath, std::string fragShdrPath);
	Model_ID createModel(std::string modelPath, Texture_ID texture_id);
	Model_ID duplicateModel(Model_ID original_model_id);
	void destroyModel(Model_ID model_id);
	Texture_ID createTexture(std::string texturePath);
	void setTextureForModel(Texture_ID texture_id, Model_ID model_id);
	void draw();
	bool windowShouldClose();
	void cleanup();
};

#endif