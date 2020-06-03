#include "graphics_layer.h"

int main() {
	GraphicsLayer grphLyr("./shaders/vert.spv", "./shaders/frag.spv");

	Texture txtr = grphLyr.createTexture("textures/viking_room.png");

	Model model_1 = grphLyr.createModel("models/viking_room.obj", txtr, glm::vec3(0.0f, 3.0f, 0.0f));
	Model model_3 = grphLyr.createModel("models/viking_room.obj", txtr, glm::vec3(0.0f, -3.0f, 0.0f));	

	int stressTestModelCount = 50;
	std::vector<Model> duplicate_IDs;
	for (int idx = 0; idx < stressTestModelCount; idx++) {
		duplicate_IDs.push_back(grphLyr.duplicateModel(model_1));
	}

	for (int idx = 0; idx < 600; idx++) {
		grphLyr.draw();
	}

	for (int idx = 0; idx < stressTestModelCount/2; idx++) {
		grphLyr.destroyModel(duplicate_IDs[idx]);
	}

	while (!grphLyr.windowShouldClose()) {
		grphLyr.draw();
	}
	grphLyr.cleanup();
}
