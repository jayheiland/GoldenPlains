#include "graphics_layer.h"

int main() {
	GraphicsLayer grphLayer;

	grphLayer.init("./shaders/vert.spv", "./shaders/frag.spv");
	Texture_ID txtr = grphLayer.createTexture("textures/viking_room.png");
	Model_ID model_1 = grphLayer.createModel("models/viking_room.obj", txtr);
	std::vector<Model_ID> duplicate_IDs;
	for (int idx = 0; idx < 2; idx++) {
		duplicate_IDs.push_back(grphLayer.duplicateModel(model_1));
	}

	for (int idx = 0; idx < 600; idx++) {
		grphLayer.draw();
	}

	for (int idx = 0; idx < 1; idx++) {
		grphLayer.destroyModel(duplicate_IDs[idx]);
	}

	while (!grphLayer.windowShouldClose()) {
		grphLayer.draw();
	}
	grphLayer.cleanup();
}
