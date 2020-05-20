#include "graphics_layer.h"

int main() {
	GraphicsLayer grphLayer;

	grphLayer.init("./shaders/vert.spv", "./shaders/frag.spv");
	Texture_ID txtr = grphLayer.createTexture("textures/viking_room.png");
	Model_ID model_1 = grphLayer.createModel("models/viking_room.obj", txtr);
	Model_ID model_2 = grphLayer.createModel("models/viking_room.obj", txtr);
	grphLayer.destroyModel(model_1);
	while (!grphLayer.windowShouldClose()) {
		grphLayer.draw();
	}
	grphLayer.cleanup();
}
