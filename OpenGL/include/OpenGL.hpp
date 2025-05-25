#pragma once
#include <window.hpp>
/*
	Class that contains the OpenGL abstractions and wrapped functions
	to use in the Window class
*/
class GL_Backend 
{
public:
	void createBuffer(std::string name, int type);
	int sendData(std::string buffName,void* databuff, size_t size);

private:
	int initStatus;

	/*
		Vectors to store different OpenGL objects
	*/
	std::vector<bufferStruct> glBuffers;	// Vector to hold all the allocated buffers

};