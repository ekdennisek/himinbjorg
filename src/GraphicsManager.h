#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
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
        void drawMesh(const Mesh * const mesh, const Material * const material, const glm::mat4 * const modelMatrix) const;
        void drawPlaneOrtho(const OrthoPlane * const plane, const Material * const material, const glm::mat4 * const modelMatrix) const;
        void drawLinesOrtho(const Lines &lines, const GLuint shader) const;
        void drawText(const GLuint vao, const GLuint vbo, const std::string text, const Material * const material, GLfloat x, GLfloat y, const int size) const;

        void setActiveCamera(const glm::mat4 * const projectionMatrix, const glm::mat4 * const viewMatrix);
        const glm::mat4 *getActivePerspectiveProjectionMatrix() const;
        const glm::mat4 *getActiveViewMatrix() const;
        const glm::mat4 &getActiveOrthoProjectionMatrix() const;
        const glm::mat4 &getActiveOrthoViewMatrix() const;

        void setDepthTest(const bool depthTest);
        glm::vec2 getTextDimensions(const std::string text, const int size) const;
        GLFWwindow *getWindow() const;
    private:
        GLFWwindow *window;
        const glm::mat4 *perspectiveProjectionMatrix;
        const glm::mat4 *perspectiveViewMatrix;
        glm::mat4 orthoProjectionMatrix;
        glm::mat4 orthoViewMatrix;
    };
}

#endif
