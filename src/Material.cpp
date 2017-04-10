#include "Material.h"
#include <cstring> // memcpy

namespace Himinbjorg
{
    Material::Material(GLuint shader, GLuint texture, float rgba[4])
    {
    	this->shader = shader;
    	this->texture = texture;
    	memcpy(this->rgba, rgba, sizeof(float)*4);
    }

    Material::Material(Material &other)
    {
    	this->shader = other.shader;
    	this->texture = other.texture;
    	memcpy(this->rgba, other.rgba, sizeof(float)*4);
    }

    Material::~Material()
    {
    }

    void Material::setShader(GLuint shader)
    {
    	this->shader = shader;
    }

    GLuint Material::getShader()
    {
    	return shader;
    }

    GLuint Material::getTexture()
    {
    	return texture;
    }
}
