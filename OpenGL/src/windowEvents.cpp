#include <window.hpp>

#define KEY_PRESS_EVENT		0
#define KEY_RELEASE_EVENT	1

void Window::handleInput(int mode) {

	// Handle when a key is pressed down
	if (mode == KEY_PRESS_EVENT) {

		// Apply the logic for the used keys
		switch (this->windowInfo.mainWindowEvent.key.key) {
		
		}
	}
	
}

/*
	This method contains the wrapping for the window events handler, we'll filter the events and call functions for specific types
*/
void Window::eventHandler() {
	while (SDL_PollEvent(&this->windowInfo.mainWindowEvent)) {
		switch (this->windowInfo.mainWindowEvent.type) {
		case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
			this->destroy();
			break;

		case SDL_EVENT_KEY_DOWN:
			this->handleInput(KEY_PRESS_EVENT);
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			this->resizeGLViewport();
			break;
		}
	}
}