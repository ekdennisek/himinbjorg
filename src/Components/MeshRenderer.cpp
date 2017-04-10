#include "MeshRenderer.h"
#include "Mesh.h"
#include "TransformComponent.h"
#include "../SceneNode.h"
#include "../GraphicsManager.h"

namespace Himinbjorg
{
    MeshRenderer::MeshRenderer(const Mesh * const mesh, const Material * const material)
    : RenderingComponent(material)
    {
    	this->mesh = mesh;
    }

    MeshRenderer::~MeshRenderer()
    {
        if(mesh) delete mesh;
    }

    void MeshRenderer::render(const GraphicsManager * const graphicsManager)
    {
    	graphicsManager->drawMesh(mesh, material, ((TransformComponent*) parent->findComponents(TRANSFORM_COMPONENT).front())->getTransformtionMatrix());
    }

    void MeshRenderer::setMesh(const Mesh * const mesh)
    {
        this->mesh = mesh;
    }

    const Mesh* MeshRenderer::getMesh() const
    {
    	return mesh;
    }
}
