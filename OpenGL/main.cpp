#include "window.hpp"

int main(void) {	
	
	Window win = Window("App", 1280, 720);

	if (win.getInitStatus() != 0) {
		win.destroy();
		return win.getInitStatus();
	}

	while (!win.shouldClose()) {
		win.eventHandler();

		win.update();
	}

	return 0;
}