#include "graphics_layer.h"

int main() {
	GraphicsLayer grphLyr("./shaders/vert.spv", "./shaders/frag.spv");

	Texture txtr = grphLyr.createTexture("textures/viking_room.png");
	Texture txtr2 = grphLyr.createTexture("textures/aggelos.jpeg");

	Model model_1 = grphLyr.createModel("models/viking_room.obj", txtr, glm::vec3(0.0f, 4.0f, 0.0f));
	Model model_2 = grphLyr.createModel("models/viking_room.obj", txtr, glm::vec3(0.0f, -4.0f, 0.0f));	

	int stressTestModelCount = 100;
	std::vector<Model> duplicate_IDs;
	for (int idx = 0; idx < stressTestModelCount; idx++) {
		duplicate_IDs.push_back(grphLyr.duplicateModel(model_1));
	}

	for (int idx = 0; idx < 250; idx++) {
		grphLyr.draw();
	}

	for (int idx = 0; idx < stressTestModelCount/2; idx++) {
		grphLyr.destroyModel(duplicate_IDs[idx]);
	}
	std::cout << "Destroyed models" << std::endl;

	//grphLyr.setTextureForModel(txtr2, model_1);
	//grphLyr.setModelPosition(model_1, glm::vec3(0.0f, 2.0f, 0.0f));
	//grphLyr.destroyTexture(txtr2);

	while (!grphLyr.windowShouldClose()) {
		grphLyr.draw();
	}
	grphLyr.cleanup();
}
