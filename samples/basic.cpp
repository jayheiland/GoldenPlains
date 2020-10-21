#include "golden_plains.h"

int main() {
	GraphicsLayer grphLyr("./shaders/vert.spv", "./shaders/frag.spv");

	grphLyr.setCamera(glm::vec3(0.0f, 2.5f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	TextureID txtr = grphLyr.createTexture("textures/viking_room.png");

	GraphObjID model_1 = grphLyr.createModel("models/viking_room.obj", txtr, glm::vec3(0.0f, 0.0f, 0.0f));

	while (!grphLyr.windowShouldClose()) {
		grphLyr.draw();
	}
	grphLyr.cleanup();
}
