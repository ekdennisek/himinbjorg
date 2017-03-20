#include "Lines.h"
#include <iostream>

namespace Himinbjorg
{
	Lines::Lines(GLfloat *vertexBuffer, int nrOfLines)
	{
		this->nrOfLines = nrOfLines;

        // Bind the VAO
        glBindVertexArray(vao);
            // Bind the VBO and upload the data to the GPU
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*nrOfLines*12, vertexBuffer, GL_STATIC_DRAW); // 12 GLfloat per line

            GLsizei stride = 3*sizeof(GLfloat) + 3*sizeof(GLfloat); // Stride calculated using the XYZRGB format
            // Configure vertex position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)0);
            glEnableVertexAttribArray(0);
            // Configure vertex color attribute
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)(3*sizeof(GLfloat)));
            glEnableVertexAttribArray(1);
        // Unbind the VAO
        glBindVertexArray(0);

        delete[] vertexBuffer;

    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "Lines::Lines(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
	}

	Lines::~Lines()
	{
	}

	int Lines::getNrOfLines()
	{
		return nrOfLines;
	}
}
