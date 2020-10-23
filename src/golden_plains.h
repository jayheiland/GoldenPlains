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
	std::vector<GraphObjID> char_models;
	Rect rect;
};

struct Button{
	GraphObjID textbox;
	GraphObjID sprite;
	void (*onLeftClick)();
};

class GraphicsLayer
{
private:
	VulkanHandler vulkHandler;
	uint id_counter;
	const uint GUI_NULL_ID = 0;
	double mousePosX, mousePosY;
	int lmbPrevState, rmbPrevState;
	TextureID font;
	double font_u_offset, font_v_offset;
	std::unordered_map<char, std::pair<double, double> > fontUVCoords;

	//graphics objects
	std::unordered_map<GraphObjID, TextBox> textBoxes;
	std::unordered_map<GraphObjID, Sprite> sprites;
	std::unordered_map<GraphObjID, Button> buttons;

	GraphObjID createChar(char character, double x, double y, uint pixWidth, uint pixHeight);
	bool mouseIsInside(Rect rect);
	void handleInteractions();

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

	GraphObjID createButton(void (*onLeftClick)(), std::string text, double x, double y, uint width, uint height);

	void remove3DModel(GraphObjID id);
	void removeTextBox(GraphObjID id);
	void removeButton(GraphObjID id);
	void removeSprite(GraphObjID id);

	TextureID createTexture(std::string texturePath);
	void setTextureForModel(TextureID texture_id, GraphObjID model_id);

	void draw();
	bool windowShouldClose();
	void cleanup();
};

#endif