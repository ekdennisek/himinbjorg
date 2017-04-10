#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/glew.h>

namespace Himinbjorg
{
    class Material
    {
    public:
        Material(const GLuint shader, const GLuint texture, const float rgba[4]);
        Material(const Material &other);
        virtual ~Material();

        // Setters
        void setShader(const GLuint shader);

        // Getters
        GLuint getShader() const;
        GLuint getTexture() const;
    private:
        GLuint shader;
        GLuint texture;
        float rgba[4]; // TODO Make use of this where possible
    };
}

#endif
