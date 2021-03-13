#include "golden_plains.h"

int main() {
	GraphicsLayer grphLyr("./shaders/vert.spv", "./shaders/frag.spv");

	grphLyr.setCamera(glm::vec3(2.5f, 2.5f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	TextureID txtr = grphLyr.createTexture("textures/viking_room.png");

	float x = 1.0f;
	float y = 1.0f;
	float z = 0.0f;
	grphLyr.createModel("models/cube.obj", txtr, glm::vec3(x, y, z));
	grphLyr.createBoundingBox(glm::vec3(x-0.5f, y-0.5f, z-0.5f), glm::vec3(x+0.5f, y+0.5f, z+0.5f));

	while (!grphLyr.windowShouldClose()) {
        GraphObjID leftClickedBox = grphLyr.getClickedBoundingBox(LMB);
        if(leftClickedBox){
            printf("You clicked the bounding box with ID equal to %d\n", leftClickedBox);
        }
		grphLyr.draw();
	}
	grphLyr.cleanup();
}
