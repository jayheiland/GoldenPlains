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
enum MouseButton{LMB, RMB};

struct Rect{
	int x,y;
	uint w,h;
};

struct Sprite{
	GraphObjID model;
	Rect rect;
};

struct TextBox{
	std::vector<GraphObjID> char_models;
	Rect rect;
};

struct Button{
	GraphObjID textbox;
	GraphObjID sprite;
	void (*onLeftClick)(GraphObjID);
};

struct BoundingBox{
	glm::vec3 minBound;
	glm::vec3 maxBound;
};

class GraphicsLayer
{
	private:
		VulkanHandler vulkHandler;
		uint id_counter;
		const uint GUI_NULL_ID = 0;
		double mousePosX, mousePosY;
		int lmbPrevState, rmbPrevState;
		GraphObjID nearestHit_LeftClick, nearestHit_RightClick;
		TextureID font;
		double font_u_offset, font_v_offset;
		std::unordered_map<char, std::pair<double, double> > fontUVCoords;

		//graphics objects
		std::unordered_map<GraphObjID, TextBox> textBoxes;
		std::unordered_map<GraphObjID, Sprite> sprites;
		std::unordered_map<GraphObjID, Button> buttons;
		std::unordered_map<GraphObjID, BoundingBox> boundingBoxes;

		GraphObjID createChar(char character, double x, double y, uint pixWidth, uint pixHeight);
		bool mouseInRect(Rect rect);
		void handleInteractions();
		GraphObjID mousePick_getNearestHit();
		void debugLog(std::string msg);

	public:
		GraphicsLayer(std::string vertShdrPath, std::string fragShdrPath);
		void setKeyEventCallback(void (*onKeyPress)(GLFWwindow*,int,int,int,int));
		void destroyModel(GraphObjID model_id);
		void destroyTexture(TextureID texture_id);
		void setModelPosition(GraphObjID model_id, glm::vec3 pos);
		void setModelRotation(GraphObjID model_id, glm::vec3 rotAxis, float rotAngle);
		void setCamera(glm::vec3 cameraPos, glm::vec3 targetPos);
		void loadFont(std::string path);
		std::pair<uint, uint> getScreenDimensions();
		GraphObjID getClickedBoundingBox(MouseButton btn);
		
		GraphObjID createModel(std::string modelPath, TextureID texture_id, glm::vec3 pos);
		GraphObjID duplicateModel(GraphObjID original_model_id);
		GraphObjID createTextBox(std::string text, double x, double y);
		GraphObjID createButton(void (*onLeftClick)(GraphObjID), std::string text, double x, double y);
		GraphObjID createSprite(TextureID texture,  double x, double y, uint width, uint height);
		GraphObjID createBoundingBox(glm::vec3 minBound, glm::vec3 maxBound);

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