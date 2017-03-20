#ifndef CLICKABLEBEHAVIORCOMPONENT_H
#define CLICKABLEBEHAVIORCOMPONENT_H

#include "BehaviorComponent.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <string>
#include <functional>

namespace Himinbjorg
{
    // Forward declaration
    class MessageBus;
    class PhysicsManager;

	class ClickableBehaviorComponent: public BehaviorComponent
	{
	public:
		ClickableBehaviorComponent(MessageBus *messageBus, PhysicsManager *physicsManager, std::string identifier);
		virtual ~ClickableBehaviorComponent();

		void onClick();

		std::string getIdentifier();
	protected:
		btCollisionShape *collisionShape;
		btDefaultMotionState *motionState;
		btRigidBody *rigidBody;

		MessageBus *messageBus;
		PhysicsManager *physicsManager;

		std::string identifier;
	};
}

#endif
