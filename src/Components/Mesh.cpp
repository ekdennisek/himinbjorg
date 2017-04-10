#include "Mesh.h"
#include <iostream>

namespace Himinbjorg
{
    Mesh::Mesh(const std::string identifier, float * const vertexBuffer, const GLsizei vertexCount)
    {
        this->identifier = identifier;
        this->vertexBuffer = vertexBuffer;
        this->vertexCount = vertexCount;

        // Bind the VAO
        glBindVertexArray(vao);
            // Bind the VBO and upload the data to the GPU
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertexCount*8, vertexBuffer, GL_STATIC_DRAW);

            // Configure vertex attributes
            GLsizei stride = 3*sizeof(GLfloat) + 2*sizeof(GLfloat) + 3*sizeof(GLfloat); // Stride calculated using the VVVTTNNN format
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (GLvoid*)(3*sizeof(GL_FLOAT)));
            glEnableVertexAttribArray(1);
        // Unbind the VAO
        glBindVertexArray(0);

    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "Mesh::Mesh(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
    }

    Mesh::Mesh(const Mesh &other)
    {
        this->identifier = other.identifier;
        this->vertexCount = other.vertexCount;
        this->vao = other.vao;
        this->vbo = other.vbo;
        this->vertexBuffer = new GLfloat[vertexCount*8];
        for(int i=0; i<vertexCount*8; i++)
        	this->vertexBuffer[i] = other.vertexBuffer[i];
    }

    Mesh::~Mesh()
    {
        if(vertexBuffer) delete[] vertexBuffer;
    }

    std::string Mesh::getIdentifier() const
    {
        return identifier;
    }
}
