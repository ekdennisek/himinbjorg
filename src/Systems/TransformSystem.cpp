#include "TransformSystem.h"
#include "../SceneNode.h"
#include "../Components/TransformComponent.h"

namespace Himinbjorg
{
	TransformSystem::TransformSystem()
	{
	}

	TransformSystem::~TransformSystem()
	{
	}

	void TransformSystem::recalculateMatrices(const SceneNode * const sceneNode, TransformComponent * const parentTransform)
	{
		// Every node contains a Transform. No need to verify it.
    	std::vector<Component*> transformComponents = sceneNode->findComponents(TRANSFORM_COMPONENT);
    	for(std::vector<Component*>::iterator it = transformComponents.begin(); it != transformComponents.end(); it++)
    	{
    		TransformComponent *transform = ((TransformComponent*)(*it));

			// Only update the matrices if they're dirty and don't belong to the root node
			if(parentTransform && transform->isDirty())
			{
				// Set dirty flag on children
				transform->makeDirty();

				// Recalculate model matrix
				transform->recalculate(parentTransform);
			}


			// Recursively call this function for every child SceneNode
			for(std::set<SceneNode*>::iterator it = sceneNode->getChildren()->begin(); it != sceneNode->getChildren()->end(); it++)
			{
				recalculateMatrices(*it, transform);
			}
    	}
	}
}
