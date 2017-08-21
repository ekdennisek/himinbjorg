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

	void RenderingComponent::setMaterial(Material *material)
	{
		this->material = material;
	}

	void RenderingComponent::setDepth(int depth)
	{
		this->depth = depth;
	}

	Material *RenderingComponent::getMaterial() const
	{
		return this->material;
	}

	int RenderingComponent::getDepth() const
	{
		return this->depth;
	}
}
