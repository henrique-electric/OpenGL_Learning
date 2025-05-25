#pragma once
// STD includes
#include <iostream>
#include <vector>
#include <fstream>

// SDL, OpenGL and external includes
#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <glm.hpp>	  

// Header files
#include <erros.hpp>   // Include the error enumaration 
#include <types.hpp>   // Contains custom data type structs
#include <OpenGL.hpp>

enum {
	KEY_PRESS_EVENT,
	KEY_RELEASE_EVENT,
};

class Window : public GL_Backend{
public:
	// Window class methods
	Window(std::string windowTitle, int width, int height);
	void eventHandler(void);
	void destroy();
	void update();
	bool shouldClose();
	int  getInitStatus();

	// Methods involving SDL stuff
	SDL_Event* getEventRef();

	// OpenGL abstraction functions

private:
	// Window class main attributes
	int initStatus;
	std::string windowName;
	int windowHeight, windowWidth;
	bool shouldCloseWindow;
	
	// SDL stuff
	SDL_WindowInfo windowInfo;

	// OpenGL stuff
	std::vector<GLuint> vertexBuffers;

	// Private Window class methods
	void refreshWindow();
	int	 initSDLWindow();

	// Window SDL event handlers
	void handleInput(int mode);

	/*
		 Private methods used to handle OpenGl
	*/
	void resizeGLViewport(); // Used to resize the OpenGl viewport, mainly called when the main window gets resized

};