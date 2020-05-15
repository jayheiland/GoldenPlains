#include "graphics_layer.h"

int main() {
	GraphicsLayer grphLayer;

	grphLayer.init();
	while (!grphLayer.windowShouldClose()) {
		grphLayer.draw();
	}
	grphLayer.cleanup();
}
