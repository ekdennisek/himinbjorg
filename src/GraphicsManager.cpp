#include "GraphicsManager.h"
#include "Material.h"
#include "Components/Mesh.h"
#include "Components/Lines.h"
#include <GL/glew.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Components/OrthoPlane.h"
#include "ResourceManager.h"

namespace Himinbjorg
{
    GraphicsManager::GraphicsManager()
    {
    	// Window dimenstions
    	// TODO Non-hardcoded
    	int width = 1368;
    	int height = 768;

    	// Init GLFW and create a window
        if(!glfwInit())
            std::cout << "Couldn't initialize GLFW.\n";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(width, height, "Himinbjörg", NULL, NULL);
        if(window == NULL)
            std::cout << "Couldn't create the desired OpenGL context.\n";
        glfwMakeContextCurrent(window);
        // Disable vsync
        //glfwSwapInterval(0);

        // Init GLEW
    	// Note that GLEW <= 1.13.0 results in a GL_INVALID_ENUM
        glewExperimental = GL_TRUE;
    	GLenum error = glewInit();
    	if(error != GLEW_OK)
    		std::cout << "Couldn't initialize GLEW: " << glewGetErrorString(error) << "\n";

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);

        perspectiveProjectionMatrix = nullptr;
        perspectiveViewMatrix = nullptr;
        orthoProjectionMatrix = glm::ortho(0.0f, (GLfloat)width, (GLfloat)height, 0.0f, 0.0f, 100.0f);
        orthoViewMatrix = glm::mat4(1.0f);

    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "GraphicsManager::GraphicsManager(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
    }

    GraphicsManager::~GraphicsManager()
    {
    	glfwDestroyWindow(window);
        glfwTerminate();
    }

    void GraphicsManager::drawMesh(const Mesh * const mesh, const Material * const material, const glm::mat4 * const modelMatrix) const
    {
    	glUseProgram(material->getShader());
    	glBindTexture(GL_TEXTURE_2D, material->getTexture());
    	glBindVertexArray(mesh->getVao());

    	// Render as wireframe
    	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    	// Projection matrix
    	GLint projectionMatrixHandle = glGetUniformLocation(material->getShader(), "projectionMatrix");
    	glUniformMatrix4fv(projectionMatrixHandle, 1, GL_FALSE, glm::value_ptr(*perspectiveProjectionMatrix));

    	// View matrix
    	GLint viewMatrixHandle = glGetUniformLocation(material->getShader(), "viewMatrix");
    	glUniformMatrix4fv(viewMatrixHandle, 1, GL_FALSE, glm::value_ptr(*perspectiveViewMatrix));

    	// Model matrix
    	GLint modelMatrixHandle = glGetUniformLocation(material->getShader(), "modelMatrix");
    	glUniformMatrix4fv(modelMatrixHandle, 1, GL_FALSE, glm::value_ptr(*modelMatrix));

    	// Draw the mesh
    	glDrawArrays(GL_TRIANGLES, 0, mesh->getVertexCount());

    	// Unbind the VAO, we don't want to accidentally operate on it
    	glBindVertexArray(0);

    	// OpenGL error checking
    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "GraphicsManager::drawMesh(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
    }

    void GraphicsManager::drawLinesOrtho(const Lines &lines, const GLuint shader) const
    {
    	glUseProgram(shader);
    	glBindVertexArray(lines.getVao());

    	// Projection matrix
    	GLint projectionMatrixHandle = glGetUniformLocation(shader, "projectionMatrix");
    	glUniformMatrix4fv(projectionMatrixHandle, 1, GL_FALSE, glm::value_ptr(orthoProjectionMatrix));

    	// View matrix
    	GLint viewMatrixHandle = glGetUniformLocation(shader, "viewMatrix");
    	glUniformMatrix4fv(viewMatrixHandle, 1, GL_FALSE, glm::value_ptr(orthoViewMatrix));

    	// Model matrix
    	GLint modelMatrixHandle = glGetUniformLocation(shader, "modelMatrix");
    	glUniformMatrix4fv(modelMatrixHandle, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

    	// Draw the line
    	glDrawArrays(GL_LINES, 0, 2*lines.getNrOfLines());

    	// Unbind the VAO, we don't want to accidentally operate on it
    	glBindVertexArray(0);

    	// OpenGL error checking
    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "GraphicsManager::drawLines(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
    }

    void GraphicsManager::drawPlaneOrtho(const OrthoPlane * const plane, const Material * const material, const glm::mat4 *modelMatrix) const
    {
    	glUseProgram(material->getShader());
    	glBindTexture(GL_TEXTURE_2D, material->getTexture());
    	glBindVertexArray(plane->getVao());

    	// Projection matrix
    	GLint projectionMatrixHandle = glGetUniformLocation(material->getShader(), "projectionMatrix");
    	glUniformMatrix4fv(projectionMatrixHandle, 1, GL_FALSE, glm::value_ptr(orthoProjectionMatrix));

    	// View matrix
    	GLint viewMatrixHandle = glGetUniformLocation(material->getShader(), "viewMatrix");
    	glUniformMatrix4fv(viewMatrixHandle, 1, GL_FALSE, glm::value_ptr(orthoViewMatrix));

    	// Model matrix
    	GLint modelMatrixHandle = glGetUniformLocation(material->getShader(), "modelMatrix");
    	glUniformMatrix4fv(modelMatrixHandle, 1, GL_FALSE, glm::value_ptr(*modelMatrix));

    	// Draw the mesh
    	glDrawArrays(GL_TRIANGLES, 0, plane->getVertexCount());

    	// Unbind the VAO, we don't want to accidentally operate on it
    	glBindVertexArray(0);

    	// OpenGL error checking
    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "GraphicsManager::drawMeshOrtho(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
    }

    void GraphicsManager::drawText(const GLuint vao, const GLuint vbo, const std::string text, const Material * const material, GLfloat x, GLfloat y, const int size) const
    {
    	Glyph *glyphs = ResourceManager::getInstance().getFont("truetype/ubuntu-font-family/Ubuntu-C.ttf", size);

    	glUseProgram(material->getShader());
    	glUniform3f(glGetUniformLocation(material->getShader(), "textColor"), 0.0f, 0.0f, 0.0f);
    	glActiveTexture(GL_TEXTURE0);
    	glBindVertexArray(vao);

    	// Prepare the ortho projection matrix
    	GLint projectionMatrixHandle = glGetUniformLocation(material->getShader(), "projection");
    	glUniformMatrix4fv(projectionMatrixHandle, 1, GL_FALSE, glm::value_ptr(orthoProjectionMatrix));

    	// Lower the text so that 0,0 points at upper left corner instead of lower left corner
    	GLfloat lowest = 0.0f;
    	for(std::string::const_iterator c = text.begin(); c != text.end(); c++)
    		if(lowest < glyphs[*c].dimensions.y)
    			lowest = glyphs[*c].dimensions.y;

    	// For every glyph, create vertices at the proper place and render
    	for(std::string::const_iterator c = text.begin(); c != text.end(); c++)
    	{
    		Glyph glyph = glyphs[*c];

    		GLfloat xPos = x + glyph.bearings.x;
    		GLfloat yPos = y + lowest - glyph.bearings.y;

    		GLfloat w = glyph.dimensions.x;
    		GLfloat h = glyph.dimensions.y;

            GLfloat vertices[6][4] = {
                    { xPos,     yPos,       0.0, 0.0 }, // Top left
                    { xPos,     yPos + h,   0.0, 1.0 }, // Bottom left
                    { xPos + w, yPos + h,   1.0, 1.0 }, // Bottom right

                    { xPos + w, yPos,       1.0, 0.0 }, // Top right
                    { xPos,     yPos,       0.0, 0.0 }, // Top left
                    { xPos + w, yPos + h,   1.0, 1.0 }  // Bottom right
            };

            glBindTexture(GL_TEXTURE_2D, glyph.textureID);

            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            glDrawArrays(GL_TRIANGLES, 0, 6);

            x += glyph.offsetToNext >> 6;
    	}
    	glBindVertexArray(0);
    	glBindTexture(GL_TEXTURE_2D, 0);
    }

    void GraphicsManager::setActiveCamera(const glm::mat4 * const projectionMatrix, const glm::mat4 * const viewMatrix)
    {
    	this->perspectiveProjectionMatrix = projectionMatrix;
    	this->perspectiveViewMatrix = viewMatrix;
    }

    const glm::mat4 *GraphicsManager::getActivePerspectiveProjectionMatrix() const
    {
    	return perspectiveProjectionMatrix;
    }

    const glm::mat4 *GraphicsManager::getActiveViewMatrix() const
    {
    	return perspectiveViewMatrix;
    }

    const glm::mat4 &GraphicsManager::getActiveOrthoProjectionMatrix() const
    {
    	return orthoProjectionMatrix;
    }

    const glm::mat4 &GraphicsManager::getActiveOrthoViewMatrix() const
    {
    	return orthoViewMatrix;
    }

    void GraphicsManager::setDepthTest(const bool depthTest)
    {
    	if(depthTest)
    		glEnable(GL_DEPTH_TEST);
    	else
    		glDisable(GL_DEPTH_TEST);
    }

    glm::vec2 GraphicsManager::getTextDimensions(const std::string text, const int size) const
    {
    	Glyph *glyphs = ResourceManager::getInstance().getFont("truetype/ubuntu-font-family/Ubuntu-C.ttf", size);

    	// Calculate the width by summing the advance of each glyph
    	GLfloat width = 0.0f;
    	for(std::string::const_iterator c = text.begin(); c != text.end(); c++)
			width += glyphs[*c].offsetToNext >> 6;

    	// Calculate the height by finding the highest glyph
    	GLfloat height = 0.0f;
    	for(std::string::const_iterator c = text.begin(); c != text.end(); c++)
    		if(glyphs[*c].dimensions.y > height)
    			height = glyphs[*c].dimensions.y;

    	return glm::vec2(width, height);
    }

    GLFWwindow *GraphicsManager::getWindow() const
    {
    	return this->window;
    }
}
