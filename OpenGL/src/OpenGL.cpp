/*
	This file will contain the definitions of all the OpenGL stuff functions 
*/

#include <OpenGL.hpp>
/*
	Function used to create a a new OpenGL buffer and also
	bind a name to it.
*/
void GL_Backend::createBuffer(std::string name, int type) {
	bufferStruct newBuffer;
	newBuffer.name		  = name;
	newBuffer.buffType    = static_cast<GLuint>(type);
	newBuffer.posOnVector = static_cast<uint>(this->glBuffers.size());

	// Invoke OpenGL API functions
	glGenBuffers(1, &newBuffer.id);

	this->glBuffers.push_back(newBuffer); // Push to the buffer vector
}


/*
	Function to delete a buffer by its name. It runs through the vector of buffers
	and deletes it
*/
int GL_Backend::deleteBuffer(std::string buffName) {

	for (bufferStruct& buffer : this->glBuffers) {
		if (buffer.name == buffName) {
			glDeleteBuffers(1, &buffer.id); //delete the buffer from OpenGL
			this->glBuffers.erase(this->glBuffers.begin() + buffer.posOnVector - 1);  // remove the buffer from the vector
			return 0;
		}
	}

	return ERROR_BUFFER_NOT_FOUND;
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
