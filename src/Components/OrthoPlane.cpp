#include "OrthoPlane.h"
#include <iostream>

namespace Himinbjorg
{
	OrthoPlane::OrthoPlane(float left, float top, float width, float height)
	: left(left), top(top), width(width), height(height)
	{
        updateVertexBuffer();
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

	void OrthoPlane::updateVertexBuffer()
	{
		vertexBuffer[0] = left; vertexBuffer[1] = top; vertexBuffer[2] = 0;					// XYZ, top left
		vertexBuffer[3] = 0; vertexBuffer[4] = 1;											// UV,  top left
		vertexBuffer[5] = left; vertexBuffer[6] = top+height; vertexBuffer[7] = 0;			// XYZ, bottom left
		vertexBuffer[8] = 0; vertexBuffer[9] = 0;											// UV,  bottom left
		vertexBuffer[10] = left+width; vertexBuffer[11] = top+height; vertexBuffer[12] = 0;	// XYZ, bottom right
		vertexBuffer[13] = 1; vertexBuffer[14] = 0;                     					// UV,  bottom right
		vertexBuffer[15] = left+width; vertexBuffer[16] = top; vertexBuffer[17] = 0;        // YXZ, top right
		vertexBuffer[18] = 1; vertexBuffer[19] = 1;                     					// UV,  top right
		vertexBuffer[20] = left; vertexBuffer[21] = top; vertexBuffer[22] = 0;              // XYZ, top left
		vertexBuffer[23] = 0; vertexBuffer[24] = 1;                     					// UV,  top left
		vertexBuffer[25] = left+width; vertexBuffer[26] = top+height; vertexBuffer[27] = 0; // XYZ, bottom right
		vertexBuffer[28] = 1; vertexBuffer[29] = 0;                    						// UV,  bottom right
	}

	void OrthoPlane::updateVbo()
	{
		glBindVertexArray(vao);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertexBuffer), vertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void OrthoPlane::setLeft(GLfloat left)
	{
		this->left = left;
		updateVertexBuffer();
		updateVbo();
	}

	void OrthoPlane::setTop(GLfloat top)
	{
		this->top = top;
		updateVertexBuffer();
		updateVbo();
	}

	void OrthoPlane::setWidth(GLfloat width)
	{
		this->width = width;
		updateVertexBuffer();
		updateVbo();
	}

	void OrthoPlane::setHeight(GLfloat height)
	{
		this->height = height;
		updateVertexBuffer();
		updateVbo();
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
