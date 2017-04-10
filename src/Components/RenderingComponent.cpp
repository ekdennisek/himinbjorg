#include "RenderingComponent.h"

namespace Himinbjorg
{
	RenderingComponent::RenderingComponent(const Material * const material, const int depth)
	: Component(RENDERING_COMPONENT)
	{
		this->material = material;
		this->depth = depth;
	}

	RenderingComponent::~RenderingComponent()
	{
	}

	bool RenderingComponent::operator<(const RenderingComponent &other) const
	{
		return depth < other.depth;
	}

	void RenderingComponent::setDepth(const int depth)
	{
		this->depth = depth;
	}

	int RenderingComponent::getDepth() const
	{
		return this->depth;
	}
}
