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
        MeshRenderer(const Mesh * const mesh, const Material *const material);
        virtual ~MeshRenderer();

        virtual void render(const GraphicsManager * const graphicsManager);

        // Setters
        void setMesh(const Mesh * const mesh);

        // Getter
        const Mesh* getMesh() const;
    private:
        const Mesh *mesh;
    };
}

#endif
