#include "ClickableOrthoPlane.h"
#include "../PhysicsManager.h"
#include "OrthoPlane.h"

namespace Himinbjorg
{
	ClickableOrthoPlane::ClickableOrthoPlane(const OrthoPlane * const plane, MessageBus * const messageBus, PhysicsManager * physicsManager, const std::string identifier)
	: ClickableComponent(messageBus, physicsManager, identifier)
	{
		float width = plane->getWidth();
		float height = plane->getHeight();
		float left = plane->getLeft() + width/2.0f;
		float top = plane->getTop() + height/2.0f;

		btQuaternion rot = btQuaternion::getIdentity();
		btVector3 pos = btVector3(left,top,-0.1f); // Note: Z must be less than 0. Since the GUI is rendered orthograpically, the value doesn't matter as long as it's less than 0
		btTransform trans = btTransform(rot, pos);

		// Create a plane at the proper place and of the proper size
		collisionShape = new btBoxShape(btVector3(width/2.0f,height/2.0f,0.0f));
		motionState = new btDefaultMotionState(trans);
		// No weight since it's a static object. We're just using Bullet to pick it.
		btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(0, motionState, collisionShape, btVector3(0,0,0));
		rigidBody = new btRigidBody(rigidBodyCI);
		rigidBody->setUserPointer(this);
		physicsManager->addRigidGUIbody(rigidBody);
	}

	ClickableOrthoPlane::~ClickableOrthoPlane()
	{
		// Remove this object from the physics world
		physicsManager->removeRigidGUIbody(rigidBody);
	}
}
