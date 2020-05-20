#include "graphics_layer.h"

int main() {
	GraphicsLayer grphLayer;

	grphLayer.init("./shaders/vert.spv", "./shaders/frag.spv");
	while (!grphLayer.windowShouldClose()) {
		grphLayer.draw();
	}
	grphLayer.cleanup();
}
