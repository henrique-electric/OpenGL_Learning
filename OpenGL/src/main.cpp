#include <window.hpp>

int main(void) {	
	
	Window win = Window("App", 1280, 720);

	if (win.getInitStatus() != 0) {
		win.destroy();
		return win.getInitStatus();
	}

	float vertexes[] = {
	   -0.5f,  -0.5f,  0.0f,
		0.5f,  -0.5f,  0.0f,
		0.0f,   0.5f,  0.0f
	};

	while (!win.shouldClose()) {
		
		win.eventHandler();
		win.update();
	}

	return 0;
}