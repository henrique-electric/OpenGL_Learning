#pragma once
#include <SDL3/SDL.h>

using SDL_WindowInfo = struct SDL_WindowInfo;

struct SDL_WindowInfo {
	SDL_Window* mainWindowPtr;
	SDL_Renderer* mainWindowRenderer;
	SDL_Event		mainWindowEvent;
	SDL_GLContext	mainWindowGLContext;
};

struct GL_InfoStruct {
	int viewPortWidth;
	int viewPortHeight;
};
