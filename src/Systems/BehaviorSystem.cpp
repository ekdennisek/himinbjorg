#include "BehaviorSystem.h"
#include "../Components/BehaviorComponent.h"
#include "../SceneNode.h"

namespace Himinbjorg
{
    BehaviorSystem::BehaviorSystem()
	{
	}

    BehaviorSystem::~BehaviorSystem()
	{
	}

    void BehaviorSystem::update(const SceneNode * const sceneNode)
    {
    	std::vector<Component*> behaviorComponents = sceneNode->findComponents(BEHAVIOR_COMPONENT);
    	for(std::vector<Component*>::iterator it = behaviorComponents.begin(); it != behaviorComponents.end(); it++)
    		((BehaviorComponent*)(*it))->update();

		// Traverse the graph recursively
		for(std::set<SceneNode*>::iterator it = sceneNode->getChildren()->begin(); it != sceneNode->getChildren()->end(); it++)
			update(*it);
    }
}
