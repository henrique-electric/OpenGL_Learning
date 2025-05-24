#pragma once
#include <SDL3/SDL.h>
#include <glad/glad.h>

using SDL_WindowInfo = struct SDL_WindowInfo;
using GL_InfoStruct = struct GL_InfoStruct;

struct SDL_WindowInfo {
	SDL_Window* mainWindowPtr;
	SDL_Renderer* mainWindowRenderer;
	SDL_Event		mainWindowEvent;
	SDL_GLContext	mainWindowGLContext;
};