#include "MeshRenderer.h"
#include "Mesh.h"
#include "TransformComponent.h"
#include "../SceneNode.h"
#include "../GraphicsManager.h"

namespace Himinbjorg
{
    MeshRenderer::MeshRenderer(Mesh *mesh, Material *material)
    : RenderingComponent(material)
    {
    	this->mesh = mesh;
    }

    MeshRenderer::~MeshRenderer()
    {
        if(mesh) delete mesh;
    }

    void MeshRenderer::render(GraphicsManager *graphicsManager)
    {
    	graphicsManager->drawMesh(mesh, material, ((TransformComponent*) parent->findComponents(TRANSFORM_COMPONENT).front())->getTransformtionMatrix());
    }

    void MeshRenderer::setMesh(Mesh *mesh)
    {
        this->mesh = mesh;
    }

    Mesh* MeshRenderer::getMesh()
    {
    	return mesh;
    }
}
