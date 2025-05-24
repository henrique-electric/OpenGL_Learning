#pragma once
#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <iostream>

#include "erros.hpp"

typedef struct SDL_WindowInfo {
	SDL_Window*		mainWindowPtr;
	SDL_Renderer*	mainWindowRenderer;
	SDL_Event		mainWindowEvent;
	SDL_GLContext	mainWindowGLContext;
} SDL_WindowInfo;

typedef struct GL_InfoStruct {
	int viewPortWidth;
	int viewPortHeight;
} GL_InfoStruct;

class Window
{
public:
	Window(std::string windowTitle, int width, int height);
	void eventHandler(void);
	void destroy();
	void update();
	bool shouldClose();

	SDL_Event* getEventRef();

	int initStatus;
private:
	std::string windowName;
	SDL_WindowInfo windowInfo;
	int windowHeight, windowWidth;
	bool shouldCloseWindow;

	// Methods
	void refreshWindow();
	int	 initSDLWindow();
	void windowResizeHandler();
};