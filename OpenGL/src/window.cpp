#include <window.hpp>

static int initOpenGL(void) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		return ERROR_INIT_GL_FUNCTIONS;
	}

	return 0;
}


/*
	Function to clean up SDL stuff and destroys OpenGL context
*/
void Window::destroy() {
	SDL_GL_DestroyContext(this->windowInfo.mainWindowGLContext);
	SDL_DestroyRenderer(this->windowInfo.mainWindowRenderer);
	SDL_DestroyWindow(this->windowInfo.mainWindowPtr);
	SDL_Quit();
	this->shouldCloseWindow = true;
}

/*
	Function to refresh the window each frame
*/
void Window::update() {
	SDL_SetRenderDrawColor(this->windowInfo.mainWindowRenderer, 0, 0, 0, 1);
	SDL_RenderClear(this->windowInfo.mainWindowRenderer);
	SDL_RenderPresent(this->windowInfo.mainWindowRenderer);
}

bool Window::shouldClose() {
	return this->shouldCloseWindow;
}

/*
	A function to initialize the main window on SDL module
*/
int Window::initSDLWindow() {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		this->initStatus = ERROR_INIT_SDL;
		return 1;
	}

	// Tries to initialize the SDL window
	this->windowInfo.mainWindowPtr = SDL_CreateWindow(this->windowName.c_str(), this->windowWidth, this->windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	if (this->windowInfo.mainWindowPtr == nullptr) {
		this->initStatus = ERROR_INIT_WINDOW;
		return 1;
	}

	// Tries to initialize the SDL renderer
	this->windowInfo.mainWindowRenderer = SDL_CreateRenderer(this->windowInfo.mainWindowPtr, NULL);
	if (this->windowInfo.mainWindowRenderer == nullptr) {
		this->initStatus = ERROR_INIT_RENDERER;
		return 1;
	}
	
	// Tries to initialize the SDL contex
	this->windowInfo.mainWindowGLContext = SDL_GL_CreateContext(this->windowInfo.mainWindowPtr);
	if (this->windowInfo.mainWindowGLContext == nullptr) {
		this->initStatus = ERROR_INIT_GL_CONTEXT;
		return 1;
	}

	this->initStatus = 0;

	return 0;
}


Window::Window(std::string windowTitle, int width, int height) {
	// Setup basic Window info
	this->windowName = windowTitle.empty() ? "Application" : windowTitle;

	this->windowHeight = height;
	this->windowWidth = width;


	// Init SDL stuff
	if (this->initSDLWindow() != 0) return;

	// Load OpenGL functions using glad
	if (initOpenGL() != 0) {
		this->initStatus = ERROR_INIT_GL_FUNCTIONS;
		return;
	}
	 
	this->shouldCloseWindow = false;
}

SDL_Event* Window::getEventRef() {
	return &this->windowInfo.mainWindowEvent;
}

int Window::getInitStatus() {
	return this->initStatus;
}
