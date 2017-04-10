#ifndef CLICKABLECOMPONENT_H
#define CLICKABLECOMPONENT_H

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

	class ClickableComponent: public Component
	{
	public:
		ClickableComponent(MessageBus * const messageBus, PhysicsManager * const physicsManager, const std::string identifier);
		virtual ~ClickableComponent();

		void onClick();

		std::string getIdentifier() const;
	protected:
		MessageBus *messageBus;
		PhysicsManager *physicsManager;
		std::string identifier;

		btCollisionShape *collisionShape;
		btDefaultMotionState *motionState;
		btRigidBody *rigidBody;
	};
}

#endif
