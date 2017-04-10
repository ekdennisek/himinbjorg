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

	int GeometryComponent::getVertexCount() const
	{
		return vertexCount;
	}

	GLuint GeometryComponent::getVao() const
	{
		return vao;
	}

	GLuint GeometryComponent::getVbo() const
	{
		return vbo;
	}
} /* namespace Himinbjorg */
