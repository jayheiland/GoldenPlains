#include "golden_plains.h"

int main() {
	GraphicsLayer grphLyr("./shaders/vert.spv", "./shaders/frag.spv");

	grphLyr.setCamera(glm::vec3(0.0f, 2.5f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	grphLyr.loadFont("textures/chars/font.png");

    grphLyr.createTextBox("The quick brown fox jumped over the lazy dog.", 0.2, 0, 0, 0);

	grphLyr.createTextBox("Peter piper picked a peck of pickled capers.", 0, 0.5, 0, 0);

	grphLyr.createTextBox("Important information about the app.", 0.6, 0.7, 0, 0);

	TextureID txtr = grphLyr.createTexture("textures/viking_room.png");

	TextureID txtr2 = grphLyr.createTexture("textures/chars/font.png");

	grphLyr.createSprite(txtr2, 0, 0, 200, 200);

	GraphObjID model_2 = grphLyr.createModel("models/viking_room.obj", txtr2, glm::vec3(0.0f, 0.5f, 0.0f));

	GraphObjID model_3 = grphLyr.createModel("models/viking_room.obj", txtr2, glm::vec3(0.0f, -0.5f, 0.0f));

	GraphObjID model_1 = grphLyr.createModel("models/viking_room.obj", txtr, glm::vec3(0.0f, 0.0f, 0.0f));

	while (!grphLyr.windowShouldClose()) {
		grphLyr.draw();
	}
	grphLyr.cleanup();
}
