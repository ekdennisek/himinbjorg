#include "OrthoPlane.h"
#include <iostream>

namespace Himinbjorg
{
	OrthoPlane::OrthoPlane(float left, float top, float width, float height)
	{
        this->left = left;
        this->top = top;
        this->width = width;
        this->height = height;

        GLfloat vertexBuffer[] = {left,top,0,              // XYZ, top left
        		                  0,1,                     // UV,  top left
								  left,top+height,0,       // XYZ, bottom left
								  0,0,                     // UV,  bottom left
								  left+width,top+height,0, // XYZ, bottom right
								  1,0,                     // UV,  bottom right
								  left+width,top,0,        // YXZ, top right
								  1,1,                     // UV,  top right
								  left,top,0,              // XYZ, top left
        		                  0,1,                     // UV,  top left
								  left+width,top+height,0, // XYZ, bottom right
								  1,0};                    // UV,  bottom right
        GLsizei stride = 3*sizeof(GLfloat) + 2*sizeof(GLfloat); // Stride calculated using the VVVTT format
        vertexCount = 6;

        // Bind the VAO
        glBindVertexArray(vao);
            // Bind the VBO and upload the data to the GPU
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertexCount*5, vertexBuffer, GL_STATIC_DRAW);

            // Configure vertex attributes
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)0); // vertex position
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (GLvoid*)(3*sizeof(GL_FLOAT))); // uv coords
            glEnableVertexAttribArray(1);
        // Unbind the VAO
        glBindVertexArray(0);

    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "OrthoPlane::OrthoPlane(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
	}

	OrthoPlane::~OrthoPlane()
	{
	}

	void OrthoPlane::setLeft(GLfloat left)
	{
		this->left = left;
	}

	void OrthoPlane::setTop(GLfloat top)
	{
		this->top = top;
	}

	void OrthoPlane::setWidth(GLfloat width)
	{
		this->width = width;
	}

	void OrthoPlane::setHeight(GLfloat height)
	{
		this->height;
	}

	GLfloat OrthoPlane::getLeft()
	{
		return left;
	}

	GLfloat OrthoPlane::getTop()
	{
		return top;
	}

	GLfloat OrthoPlane::getWidth()
	{
		return width;
	}

	GLfloat OrthoPlane::getHeight()
	{
		return height;
	}
}
