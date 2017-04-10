#include "InputSystem.h"
#include "../SceneNode.h"
#include "../Components/InputComponent.h"

namespace Himinbjorg
{
	InputSystem::InputSystem(const SceneNode * const sceneRoot)
	{
		this->sceneRoot = sceneRoot;
	}

	InputSystem::~InputSystem()
	{
	}

	void InputSystem::update()
	{
		traverse(sceneRoot);
	}

	void InputSystem::traverse(const SceneNode * const sceneNode)
	{
    	std::vector<Component*> inputComponents = sceneNode->findComponents(INPUT_COMPONENT);
    	for(std::vector<Component*>::iterator it = inputComponents.begin(); it != inputComponents.end(); it++)
    		((InputComponent*)(*it))->readKeys();

		for(std::set<SceneNode*>::iterator it = sceneNode->getChildren()->begin(); it != sceneNode->getChildren()->end(); it++)
			traverse(*it);
	}
}
