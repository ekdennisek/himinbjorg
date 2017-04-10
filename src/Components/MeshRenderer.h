#ifndef MESHRENDERINGCOMPONENT_H
#define MESHRENDERINGCOMPONENT_H

#include "RenderingComponent.h"

namespace Himinbjorg
{
    //Forward declarations
    class Mesh;
    class Material;
    class GraphicsManager;

    class MeshRenderer : public RenderingComponent
    {
    public:
        MeshRenderer(Mesh *mesh, Material *material);
        virtual ~MeshRenderer();

        virtual void render(GraphicsManager *graphicsManager);

        // Setters
        void setMesh(Mesh *mesh);

        // Getter
        Mesh* getMesh();
    private:
        Mesh *mesh;
    };
}

#endif
