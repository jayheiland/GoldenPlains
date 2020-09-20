#ifndef GRAPHICS_LAYER_H
#define GRAPHICS_LAYER_H

#include <string>
#include <unordered_map>
#include <iostream>

#include "vulkan_handler.h"

typedef uint32_t Model;
typedef uint32_t Texture;

class GraphicsLayer
{
private:
	VulkanHandler vulkHandler;
	uint32_t id_counter;
	std::unordered_map<char, Texture> charTextures;
public:
	GraphicsLayer(std::string vertShdrPath, std::string fragShdrPath);
	Model createModel(std::string modelPath, Texture texture_id, glm::vec3 pos);
	Model duplicateModel(Model original_model_id);
	void destroyModel(Model model_id);
	void destroyTexture(Texture texture_id);
	void setModelPosition(Model model_id, glm::vec3 pos);
	void setCamera(glm::vec3 cameraPos, glm::vec3 targetPos);
	void loadCharTextures(std::string directory);
	void createChar(char character, glm::vec2 pos);

	Texture createTexture(std::string texturePath);
	void setTextureForModel(Texture texture_id, Model model_id);

	void draw();
	bool windowShouldClose();
	void cleanup();
};

#endif