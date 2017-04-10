#ifndef MESH_H
#define MESH_H

#include <string>
#include "GeometryComponent.h"

namespace Himinbjorg
{
    class Mesh : public GeometryComponent
    {
    public:
        Mesh(const std::string identifier, float * const vertexBuffer, const GLsizei vertexCount);
        Mesh(const Mesh &other);
        virtual ~Mesh();

        std::string getIdentifier() const;
    private:
        std::string identifier;
        GLfloat *vertexBuffer;
    };
}

#endif
