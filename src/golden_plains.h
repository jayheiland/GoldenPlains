#ifndef GRAPHICS_LAYER_H
#define GRAPHICS_LAYER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

#include "vulkan_handler.h"

typedef uint32_t Model;
typedef uint32_t Texture;
typedef uint32_t TextBox;

class GraphicsLayer
{
private:
	VulkanHandler vulkHandler;
	uint32_t id_counter;
	Texture font;
	double font_u_offset, font_v_offset;
	std::unordered_map<char, std::pair<double, double> > fontUVCoords;
	std::unordered_map<TextBox, std::vector<uint32_t> > textBoxes;
	uint32_t createChar(char character, double x, double y);
public:
	GraphicsLayer(std::string vertShdrPath, std::string fragShdrPath);
	Model createModel(std::string modelPath, Texture texture_id, glm::vec3 pos);
	Model duplicateModel(Model original_model_id);
	void destroyModel(Model model_id);
	void destroyTexture(Texture texture_id);
	void setModelPosition(Model model_id, glm::vec3 pos);
	void setCamera(glm::vec3 cameraPos, glm::vec3 targetPos);
	void loadFont(std::string path);
	TextBox createTextBox(std::string text, double x, double y, double width, double height);

	Texture createTexture(std::string texturePath);
	void setTextureForModel(Texture texture_id, Model model_id);

	void draw();
	bool windowShouldClose();
	void cleanup();
};

#endif