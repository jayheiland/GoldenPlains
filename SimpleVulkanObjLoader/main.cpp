#include "graphics_layer.h"

int main() {
	GraphicsLayer grphLayer;

	grphLayer.init("./shaders/vert.spv", "./shaders/frag.spv");
	Texture_ID txtr = grphLayer.createTexture("textures/viking_room.png");
	Texture_ID txtr2 = grphLayer.createTexture("textures/chalet.jpg");

	Model_ID model_1 = grphLayer.createModel("models/viking_room.obj", txtr, glm::vec3(0.0f, 3.0f, 0.0f));
	Model_ID model_3 = grphLayer.createModel("models/viking_room.obj", txtr, glm::vec3(0.0f, -3.0f, 0.0f));
	

	std::vector<Model_ID> duplicate_IDs;
	for (int idx = 0; idx < 50; idx++) {
		duplicate_IDs.push_back(grphLayer.duplicateModel(model_1));
	}

	for (int idx = 0; idx < 600; idx++) {
		grphLayer.draw();
	}

	for (int idx = 0; idx < 25; idx++) {
		grphLayer.destroyModel(duplicate_IDs[idx]);
	}

	while (!grphLayer.windowShouldClose()) {
		grphLayer.draw();
	}
	grphLayer.cleanup();
}
