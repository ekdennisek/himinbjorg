#include "ClickableBehaviorComponent.h"
#include "../MessageBus.h"

namespace Himinbjorg
{
	ClickableBehaviorComponent::ClickableBehaviorComponent(MessageBus *messageBus, PhysicsManager *physicsManager, std::string identifier)
	: BehaviorComponent()
	{
		this->messageBus = messageBus;
		this->physicsManager = physicsManager;
		this->identifier = identifier;

		collisionShape = nullptr;
		motionState = nullptr;
		rigidBody = nullptr;
	}

	ClickableBehaviorComponent::~ClickableBehaviorComponent()
	{
		// Deallocate everything
		if(rigidBody) delete rigidBody;
		if(motionState) delete motionState;
		if(collisionShape) delete collisionShape;
	}

	void ClickableBehaviorComponent::onClick()
	{
		char *dataPointer = new char[identifier.size()+1];
		memcpy(dataPointer, identifier.c_str(), identifier.size()+1);
		Message *msg = new Message(Message::GUI_INPUT, Message::NONE, dataPointer);
		messageBus->sendMessage(msg);
	}

	std::string ClickableBehaviorComponent::getIdentifier()
	{
		return identifier;
	}
}
