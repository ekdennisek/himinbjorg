#ifndef MESH_H
#define MESH_H

#include <string>
#include "GeometryComponent.h"

namespace Himinbjorg
{
    class Mesh : public GeometryComponent
    {
    public:
        Mesh(std::string identifier, float *vertexBuffer, GLsizei vertexCount);
        Mesh(const Mesh &other);
        virtual ~Mesh();

        std::string getIdentifier();
    private:
        std::string identifier;
        GLfloat *vertexBuffer;
    };
}

#endif
