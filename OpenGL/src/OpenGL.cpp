/*
	This file will contain the definitions of all the OpenGL stuff functions 
*/

#include <OpenGL.hpp>

void Window::resizeGLViewport() {
	SDL_GetWindowSize(this->windowInfo.mainWindowPtr, &this->windowWidth, &this->windowHeight);
	
	// Cast the dimension to GLsizei just to make sure there won't be any problem
	GLsizei width  = static_cast<GLsizei>(this->windowWidth);
	GLsizei height = static_cast<GLsizei>(this->windowHeight);

	glViewport(0, 0, width, height);
}

/*
	Function used to create a a new OpenGL buffer and also
	bind a name to it.
*/
void GL_Backend::createBuffer(std::string name, int type) {
	bufferStruct newBuffer;
	newBuffer.name		= name;
	newBuffer.buffType  = static_cast<GLuint>(type);

	// Invoke OpenGL API functions
	glGenBuffers(1, &newBuffer.id);

	this->glBuffers.push_back(newBuffer); // Push to the buffer vector
}

/*
	This function abstracts all the process to select the buffer
	and bind the data, just need the name that identifies the buffer.
*/

int GL_Backend::sendData(std::string buffName, void* databuff, size_t size) {
	if (databuff == nullptr) return ERROR_NULL_DATA_BUFF;

	GLsizeiptr casted_size = static_cast<GLsizeiptr>(size); // cast the size tipe just to make sure that nothing bad will happen

	// Run through the vector of created buffers searching for the correct name
	for (bufferStruct& buffer : this->glBuffers) {
		if (buffer.name == buffName) {
			glBindBuffer(buffer.buffType, buffer.id);
			glBufferData(buffer.buffType, casted_size, databuff, GL_DYNAMIC_DRAW);
			return 0;
		}
	}

	return ERROR_BUFFER_NOT_FOUND;
}
