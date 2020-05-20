#include "graphics_layer.h"

int main() {
	GraphicsLayer grphLayer;

	grphLayer.init("./shaders/vert.spv", "./shaders/frag.spv");
	Texture_ID txtr = grphLayer.loadTexture("textures/chalet.jpg");
	grphLayer.loadModel("models/chalet.obj", txtr);
	while (!grphLayer.windowShouldClose()) {
		grphLayer.draw();
	}
	grphLayer.cleanup();
}
