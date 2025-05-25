#pragma once
#include <SDL3/SDL.h>
#include <glad/glad.h>

// Typedefs for structs
using SDL_WindowInfo = struct SDL_WindowInfo;
using GL_InfoStruct  = struct GL_InfoStruct;
using bufferStruct   = struct bufferStruct;
using GL_Vertex		 = struct GL_Vertex;

// Typedefs for data types
using uint = unsigned int;


// Structs related to the window and SDL

/*
	A struct to hold Critical info to the SDL info
*/
struct SDL_WindowInfo {
	SDL_Window	   *mainWindowPtr;
	SDL_Renderer   *mainWindowRenderer;
	SDL_Event		mainWindowEvent;
	SDL_GLContext	mainWindowGLContext;
};



// structs related to OpenGL and the GL_Backend class

/* 
	A struct to hold a variable to store the id of the buffer
	and also a name to make easier to identify
*/
struct bufferStruct {
	std::string name;
	uint		id;
	GLuint		buffType;

};


struct GL_Vertex {
	float* buff; // buffer containing the data related to a vertex
	size_t buffSize;

};

enum {
	RAW_ARRAY_GL_BUFFER
};