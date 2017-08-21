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
        void setTexture(GLuint texture);
        void setColor(float *rgba);

        // Getters
        GLuint getShader() const;
        GLuint getTexture() const;
        const float *getColor() const;
    private:
        GLuint shader;
        GLuint texture;
        float rgba[4]; // TODO Make use of this where possible
    };
}

#endif
