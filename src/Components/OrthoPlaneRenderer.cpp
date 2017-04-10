#include "OrthoPlaneRenderer.h"
#include "../GraphicsManager.h"
#include "../SceneNode.h"
#include "TransformComponent.h"

namespace Himinbjorg
{
	OrthoPlaneRenderer::OrthoPlaneRenderer(const OrthoPlane * const plane, const Material * const material, const int depth)
	: RenderingComponent(material, depth)
	{
		this->plane = plane;
	}

	OrthoPlaneRenderer::~OrthoPlaneRenderer()
	{
	}

	void OrthoPlaneRenderer::render(const GraphicsManager * const graphicsManager)
	{
		TransformComponent *transform = (TransformComponent*) parent->findComponents(TRANSFORM_COMPONENT).front();
		graphicsManager->drawPlaneOrtho(plane, material, transform->getTransformtionMatrix());
	}
}
