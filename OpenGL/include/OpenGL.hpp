#pragma once

// STD includes
#include <fstream>
#include <vector>

// Header files
#include <types.hpp>
#include <erros.hpp>

/*
	Class that contains the OpenGL abstractions and wrapped functions
	to use in the Window class
*/
class GL_Backend 
{
public:
	void createBuffer(std::string name, int type);
	int	 deleteBuffer(std::string buffName);
	int  sendData(std::string buffName,void* databuff, size_t size);
	void newVertex(float* pos, size_t size);


private:
	std::ifstream fileStreaming; // used to read shader files

	/*
		Vectors to store different OpenGL objects
	*/
	std::vector<bufferStruct> glBuffers;	// Vector to hold all the allocated buffers

};