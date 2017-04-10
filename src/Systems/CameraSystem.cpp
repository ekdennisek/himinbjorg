#include "CameraSystem.h"
#include "../Components/CameraComponent.h"
#include "../SceneNode.h"

namespace Himinbjorg
{
	CameraSystem::CameraSystem(GraphicsManager *graphicsManager)
	{
		this->graphicsManager = graphicsManager;
	}

	CameraSystem::~CameraSystem()
	{
	}

	void CameraSystem::update(SceneNode *sceneNode)
	{
		// Update every CameraComponent
    	std::vector<Component*> cameraComponents = sceneNode->findComponents(CAMERA_COMPONENT);
    	for(std::vector<Component*>::iterator it = cameraComponents.begin(); it != cameraComponents.end(); it++)
    		((CameraComponent*)(*it))->update(graphicsManager);

		// Traversal
		for(std::set<SceneNode*>::iterator it = sceneNode->getChildren()->begin(); it != sceneNode->getChildren()->end(); it++)
			update(*it);
	}
}
