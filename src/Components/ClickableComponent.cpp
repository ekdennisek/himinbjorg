#include "ClickableComponent.h"
#include "../MessageBus.h"
#include "Message.h"

namespace Himinbjorg
{
	ClickableComponent::ClickableComponent(MessageBus *messageBus, PhysicsManager *physicsManager, std::string identifier)
	: Component(CLICKABLE_COMPONENT)
	{
		this->messageBus = messageBus;
		this->physicsManager = physicsManager;
		this->identifier = identifier;

		collisionShape = nullptr;
		motionState = nullptr;
		rigidBody = nullptr;
	}

	ClickableComponent::~ClickableComponent()
	{
		// Deallocate everything
		if(rigidBody) delete rigidBody;
		if(motionState) delete motionState;
		if(collisionShape) delete collisionShape;
	}

	void ClickableComponent::onClick()
	{
		char *dataPointer = new char[identifier.size()+1];
		memcpy(dataPointer, identifier.c_str(), identifier.size()+1);
		Message *msg = new Message(Message::GUI_INPUT, Message::NONE, dataPointer);
		messageBus->sendMessage(msg);
	}

	std::string ClickableComponent::getIdentifier()
	{
		return identifier;
	}
}
