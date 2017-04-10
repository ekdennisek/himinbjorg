#ifndef ORTHOPLANERENDERINGCOMPONENT_H
#define ORTHOPLANERENDERINGCOMPONENT_H

#include "RenderingComponent.h"

namespace Himinbjorg
{
    // Forward declarations
    class GraphicsManager;
    class Material;
    class OrthoPlane;

	class OrthoPlaneRenderer: public RenderingComponent
	{
	public:
		OrthoPlaneRenderer(const OrthoPlane *const plane, const Material *const material, const int depth);
		virtual ~OrthoPlaneRenderer();

		void render(const GraphicsManager * const graphicsManager);
	private:
		const OrthoPlane *plane;
	};
}

#endif
