#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/glew.h>

namespace Himinbjorg
{
    class Material
    {
    public:
        Material(GLuint shader, GLuint texture, float rgba[4]);
        Material(Material &other);
        virtual ~Material();

        // Setters
        void setShader(GLuint shader);

        // Getters
        GLuint getShader();
        GLuint getTexture();
    private:
        GLuint shader;
        GLuint texture;
        float rgba[4]; // TODO Make use of this where possible
    };
}

#endif
