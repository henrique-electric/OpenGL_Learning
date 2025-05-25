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
		glClear(GL_COLOR_BUFFER_BIT);
		win.eventHandler();
		glBegin(GL_TRIANGLES);
		glVertex2d(-0.5f, -0.5f);
		glVertex2d(0.0f, 0.5f);
		glVertex2d(0.5f, -0.5f);
		glEnd();
		
		//SDL_GL_SwapWindow(win.windowInfo.mainWindowPtr);
		//win.update();
	}

	return 0;
}