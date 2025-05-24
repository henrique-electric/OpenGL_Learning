/*
	This file will contain the definitions of all the OpenGL stuff functions 
*/

#include "window.hpp"

void Window::resizeGLViewport() {
	SDL_GetWindowSize(this->windowInfo.mainWindowPtr, &this->windowWidth, &this->windowHeight);
	
	// Cast the dimension to GLsizei just to make sure there won't be any problem
	GLsizei width  = static_cast<GLsizei>(this->windowWidth);
	GLsizei height = static_cast<GLsizei>(this->windowHeight);

	glViewport(0, 0, width, height);
}