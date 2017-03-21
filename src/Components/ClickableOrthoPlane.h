#ifndef CLICKABLEORTHOPLANEBEHAVIORCOMPONENT_H
#define CLICKABLEORTHOPLANEBEHAVIORCOMPONENT_H

#include "ClickableComponent.h"

namespace Himinbjorg
{
    // Forward declarations
    class PhysicsManager;
    class OrthoPlane;

	class ClickableOrthoPlane : public ClickableComponent
	{
	public:
		ClickableOrthoPlane(OrthoPlane *plane, MessageBus *messageBus, PhysicsManager *physicsManager, std::string identifier);
		virtual ~ClickableOrthoPlane();
	};
}

#endif
