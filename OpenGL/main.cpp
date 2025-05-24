#include "window.hpp"

int main(void) {	
	
	Window win = Window("App", 1280, 720);

	if (win.initStatus != 0) {
		win.destroy();
		return win.initStatus;
	}

	while (!win.shouldClose()) {
		while (SDL_PollEvent(win.getEventRef())) {
			win.eventHandler();
		}

		win.update();
	}

	return 0;
}