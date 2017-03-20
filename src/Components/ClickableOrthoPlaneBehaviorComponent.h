#ifndef CLICKABLEORTHOPLANEBEHAVIORCOMPONENT_H
#define CLICKABLEORTHOPLANEBEHAVIORCOMPONENT_H

#include "ClickableBehaviorComponent.h"

namespace Himinbjorg
{
    // Forward declarations
    class PhysicsManager;
    class OrthoPlane;

	class ClickableOrthoPlaneBehaviorComponent: public ClickableBehaviorComponent	// TODO Semtantically correct???
	{
	public:
		ClickableOrthoPlaneBehaviorComponent(OrthoPlane *plane, MessageBus *messageBus, PhysicsManager *physicsManager, std::string identifier);
		virtual ~ClickableOrthoPlaneBehaviorComponent();

		void update();
	};
}

#endif
