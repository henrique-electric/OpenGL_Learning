#pragma once
#include <SDL3/SDL.h>
#include <glad/glad.h>

using SDL_WindowInfo = struct SDL_WindowInfo;
using GL_InfoStruct  = struct GL_InfoStruct;
using bufferStruct   = struct bufferStruct;

using uint = unsigned int;

struct SDL_WindowInfo {
	SDL_Window* mainWindowPtr;
	SDL_Renderer* mainWindowRenderer;
	SDL_Event		mainWindowEvent;
	SDL_GLContext	mainWindowGLContext;
};

/* 
	A struct to hold a variable to store the id of the buffer
	and also a name to make easier to identify
*/
struct bufferStruct {
	std::string name;
	uint		id;
	GLuint		buffType;
};

enum {
	RAW_ARRAY_GL_BUFFER
};