#include "Material.h"
#include <cstring> // memcpy

namespace Himinbjorg
{
    Material::Material(const GLuint shader, const GLuint texture, const float rgba[4])
    {
    	this->shader = shader;
    	this->texture = texture;
    	memcpy(this->rgba, rgba, sizeof(float)*4);
    }

    Material::Material(const Material &other)
    {
    	this->shader = other.shader;
    	this->texture = other.texture;
    	memcpy(this->rgba, other.rgba, sizeof(float)*4);
    }

    Material::~Material()
    {
    }

    void Material::setShader(const GLuint shader)
    {
    	this->shader = shader;
    }

    GLuint Material::getShader() const
    {
    	return shader;
    }

    GLuint Material::getTexture() const
    {
    	return texture;
    }
}
