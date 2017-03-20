#include "OrthoPlaneRenderer.h"
#include "../GraphicsManager.h"
#include "../SceneNode.h"
#include "TransformComponent.h"

namespace Himinbjorg
{
	OrthoPlaneRenderer::OrthoPlaneRenderer(OrthoPlane *plane, Material *material, int depth)
	: RenderingComponent(material, depth)
	{
		this->plane = plane;
	}

	OrthoPlaneRenderer::~OrthoPlaneRenderer()
	{
	}

	void OrthoPlaneRenderer::render(GraphicsManager *graphicsManager)
	{
		TransformComponent *transform = (TransformComponent*) parent->findComponents(TRANSFORM_COMPONENT).front();
		graphicsManager->drawPlaneOrtho(plane, material, transform->getTransformtionMatrix());
	}
}
