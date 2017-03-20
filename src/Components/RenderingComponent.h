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
		RenderingComponent(Material *material, int depth = -1);
		virtual ~RenderingComponent();
		bool operator<(const RenderingComponent &other);

		virtual void render(GraphicsManager *graphicsManager) = 0;

		// Setters
		void setMaterial(Material *material);
		void setDepth(int depth);

		// Getters
		Material *getMaterial();
		int getDepth();
	protected:
		Material *material;
		int depth; // Used to determine draw order
	};
}

#endif
