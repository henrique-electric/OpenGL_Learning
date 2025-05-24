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