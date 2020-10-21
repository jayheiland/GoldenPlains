#include "golden_plains.h"

int main() {
	GraphicsLayer grphLyr("./shaders/vert.spv", "./shaders/frag.spv");

	grphLyr.setCamera(glm::vec3(0.0f, 2.5f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	grphLyr.loadFont("textures/chars/font.png");

    grphLyr.createTextBox("The quick brown fox jumped over the lazy dog.", 0, 0, 0, 0);

	//grphLyr.createTextBox("Attack! Now!", 0, 0.5, 0, 0);

	//grphLyr.createTextBox("Important information about the game.", -0.6, 0.7, 0, 0);

	while (!grphLyr.windowShouldClose()) {
		grphLyr.draw();
	}
	grphLyr.cleanup();
}
