#pragma once
#include <SDL3/SDL.h>

typedef struct SDL_WindowInfo {
	SDL_Window* mainWindowPtr;
	SDL_Renderer* mainWindowRenderer;
	SDL_Event		mainWindowEvent;
	SDL_GLContext	mainWindowGLContext;
} SDL_WindowInfo;

typedef struct GL_InfoStruct {
	int viewPortWidth;
	int viewPortHeight;
} GL_InfoStruct;
