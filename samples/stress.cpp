#include "golden_plains.h"

int main(int argc, char **argv) {
	GraphicsLayer grphLyr("./shaders/vert.spv", "./shaders/frag.spv");

	grphLyr.setCamera(glm::vec3(42.0f, 42.0f, 42.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	TextureID txtr = grphLyr.createTexture("textures/viking_room.png");

	GraphObjID model_1 = grphLyr.createModel("models/viking_room.obj", txtr, glm::vec3(-30.0f, -30.0f, 0.0f));

	int stressTestModelCount = atoi(argv[1])-1;
	int side = (int)sqrt(stressTestModelCount);
	double spacing = 1.8;
	std::vector<GraphObjID> duplicate_IDs;
	for (int x = 0; x < side; x++) {
		for (int y = 0; y < side; y++) {
			GraphObjID dup = grphLyr.duplicateModel(model_1);
			grphLyr.setModelPosition(dup, glm::vec3((x - (side * 0.5)) * spacing, (y - (side * 0.5)) * spacing, 0.0f));
			duplicate_IDs.push_back(dup);
		}
	}

	for (int idx = 0; idx < 150; idx++) {
		grphLyr.draw();
	}

	for (int idx = 0; idx < (stressTestModelCount/2)+1; idx++) {
		grphLyr.destroyModel(duplicate_IDs[idx]);
	}

	while (!grphLyr.windowShouldClose()) {
		grphLyr.draw();
	}
	grphLyr.cleanup();
}
