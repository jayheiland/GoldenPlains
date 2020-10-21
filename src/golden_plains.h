#ifndef GRAPHICS_LAYER_H
#define GRAPHICS_LAYER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

#include "vulkan_handler.h"

typedef uint GraphObjID;
typedef uint TextureID;

struct Rect{
	int x,y;
	uint w,h;
};

struct Sprite{
	TextureID texture_id;
	Rect rect;
};

struct TextBox{
	std::vector<uint32_t> char_models;
	Rect rect;
};

union Button{
	TextBox textbox;
	Sprite sprite;
};

class GraphicsLayer
{
private:
	VulkanHandler vulkHandler;
	uint32_t id_counter;
	TextureID font;
	double font_u_offset, font_v_offset;
	std::unordered_map<char, std::pair<double, double> > fontUVCoords;
	std::unordered_map<GraphObjID, TextBox> textBoxes;
	uint32_t createChar(char character, double x, double y, int pixWidth, int pixHeight);
public:
	GraphicsLayer(std::string vertShdrPath, std::string fragShdrPath);
	GraphObjID createModel(std::string modelPath, TextureID texture_id, glm::vec3 pos);
	GraphObjID duplicateModel(GraphObjID original_model_id);
	void destroyModel(GraphObjID model_id);
	void destroyTexture(TextureID texture_id);
	void setModelPosition(GraphObjID model_id, glm::vec3 pos);
	void setCamera(glm::vec3 cameraPos, glm::vec3 targetPos);
	void loadFont(std::string path);

	GraphObjID createTextBox(std::string text, double x, double y, uint width, uint height);

	GraphObjID createButton(std::string text, double x, double y, uint width, uint height);

	void remove(GraphObjID id);

	TextureID createTexture(std::string texturePath);
	void setTextureForModel(TextureID texture_id, GraphObjID model_id);

	void draw();
	bool windowShouldClose();
	void cleanup();
};

#endif