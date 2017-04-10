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
		ClickableOrthoPlane(const OrthoPlane * const plane, MessageBus * const messageBus, PhysicsManager * const physicsManager, const std::string identifier);
		virtual ~ClickableOrthoPlane();
	};
}

#endif
