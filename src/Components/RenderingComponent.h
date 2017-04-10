#ifndef RENDERINGCOMPONENT_H
#define RENDERINGCOMPONENT_H

#include "Component.h"

namespace Himinbjorg
{
    // Forward declarations
    class Material;
    class GraphicsManager;

	class RenderingComponent: public Component
	{
	public:
		RenderingComponent(const Material * const material, const int depth = -1);
		virtual ~RenderingComponent();
		bool operator<(const RenderingComponent &other) const;

		virtual void render(const GraphicsManager * const graphicsManager) = 0;

		// Setters
		void setMaterial(const Material * const material);
		void setDepth(const int depth);

		// Getters
		Material *getMaterial() const;
		int getDepth() const;
	protected:
		const Material *material;
		int depth; // Used to determine draw order
	};
}

#endif
