#include "golden_plains.h"

int main(int argc, char **argv) {
	GraphicsLayer grphLyr("./shaders/vert.spv", "./shaders/frag.spv");

	grphLyr.setCamera(glm::vec3(4.0f, 4.0f, 8.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	Texture txtr = grphLyr.createTexture("textures/viking_room.png");

	Model model_1 = grphLyr.createModel("models/viking_room.obj", txtr, glm::vec3(-2.0f, 0.0f, 0.0f));

	int stressTestModelCount = atoi(argv[1])-1;
	std::vector<Model> duplicate_IDs;
	for (int idx = 0; idx < stressTestModelCount; idx++) {
		Model dup = grphLyr.duplicateModel(model_1);
		grphLyr.setModelPosition(dup, glm::vec3(0.0f, (idx - (stressTestModelCount * 0.5)) * 0.01, 0.0f));
		duplicate_IDs.push_back(dup);
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
