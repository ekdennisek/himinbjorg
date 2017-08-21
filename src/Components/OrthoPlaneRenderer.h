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
		OrthoPlaneRenderer(OrthoPlane *plane, Material *material, int depth);
		virtual ~OrthoPlaneRenderer();

		void render(GraphicsManager *graphicsManager);

		void setPlane(OrthoPlane *plane);

		OrthoPlane *getPlane();
	private:
		OrthoPlane *plane;
	};
}

#endif
