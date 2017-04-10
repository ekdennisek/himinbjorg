#include "GeometryComponent.h"
#include <iostream>

namespace Himinbjorg
{
	GeometryComponent::GeometryComponent()
	: Component(GEOMETRY_COMPONENT)
	{
		vertexCount = 0;

		// Create buffers
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);

		GLenum errorCode = GL_NO_ERROR;
		while((errorCode = glGetError()) != GL_NO_ERROR)
			std::cout << "GeometryComponent::GeometryComponent(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
	}

	GeometryComponent::~GeometryComponent()
	{
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);

    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "GeometryComponent::~GeometryComponent(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
	}

	int GeometryComponent::getVertexCount()
	{
		return vertexCount;
	}

	GLuint GeometryComponent::getVao()
	{
		return vao;
	}

	GLuint GeometryComponent::getVbo()
	{
		return vbo;
	}
} /* namespace Himinbjorg */
