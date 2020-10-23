#include "golden_plains.h"

void on_click(){
	printf("%s\n", "You clicked the button!");
}

int main() {
	GraphicsLayer grphLyr("./shaders/vert.spv", "./shaders/frag.spv");

	grphLyr.setCamera(glm::vec3(0.0f, 2.5f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	grphLyr.loadFont("textures/chars/font.png");

    grphLyr.createButton(on_click, "Click here!", 0, 0, 150, 40);

	while (!grphLyr.windowShouldClose()) {
		grphLyr.draw();
	}
	grphLyr.cleanup();
}
