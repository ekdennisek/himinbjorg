#include "RenderingComponent.h"

namespace Himinbjorg
{
	RenderingComponent::RenderingComponent(Material *material, int depth)
	: Component(RENDERING_COMPONENT)
	{
		this->material = material;
		this->depth = depth;
	}

	RenderingComponent::~RenderingComponent()
	{
	}

	bool RenderingComponent::operator<(const RenderingComponent &other)
	{
		return depth < other.depth;
	}

	void RenderingComponent::setDepth(int depth)
	{
		this->depth = depth;
	}

	int RenderingComponent::getDepth()
	{
		return this->depth;
	}
}
