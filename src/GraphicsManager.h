#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../lib/glm/glm/mat4x4.hpp"
#include <string>

namespace Himinbjorg
{
    // Forward declaration
    class Mesh;
    class Material;
    class Lines;
    class OrthoPlane;

    class GraphicsManager
    {
    public:
        GraphicsManager();
        ~GraphicsManager();

        // TODO Create a somewhat unified interface
        void drawMesh(Mesh *mesh, Material *material, glm::mat4 *modelMatrix);
        void drawPlaneOrtho(OrthoPlane *plane, Material *material, glm::mat4 *modelMatrix);
        void drawLinesOrtho(Lines &lines, GLuint shader);
        void drawText(GLuint vao, GLuint vbo, std::string text, Material *material, GLfloat x, GLfloat y, int size);

        void setActiveCamera(glm::mat4 *projectionMatrix, glm::mat4 *viewMatrix);
        glm::mat4 *getActivePerspectiveProjectionMatrix();
        glm::mat4 *getActiveViewMatrix();
        const glm::mat4 &getActiveOrthoProjectionMatrix();
        const glm::mat4 &getActiveOrthoViewMatrix();

        void setDepthTest(bool depthTest);
        glm::vec2 getTextDimensions(std::string text, int size);
        GLFWwindow *getWindow();
    private:
        GLFWwindow *window;
        glm::mat4 *perspectiveProjectionMatrix;
        glm::mat4 *perspectiveViewMatrix;
        glm::mat4 orthoProjectionMatrix;
        glm::mat4 orthoViewMatrix;
    };
}

#endif
