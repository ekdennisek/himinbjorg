#include "RenderingSystem.h"
#include "../SceneNode.h"
#include "../Components/CameraComponent.h"
#include "../Components/MeshRenderer.h"
#include "../GraphicsManager.h"

namespace Himinbjorg {

	RenderingSystem::RenderingSystem(GraphicsManager *graphicsManager)
	{
		this->graphicsManager = graphicsManager;
	}

	RenderingSystem::~RenderingSystem()
	{
	}

	void RenderingSystem::buildQueue(SceneNode *sceneNode)
	{
		// Render the current object
    	std::vector<Component*> renderingComponents = sceneNode->findComponents(RENDERING_COMPONENT);
    	for(std::vector<Component*>::iterator it = renderingComponents.begin(); it != renderingComponents.end(); it++)
    		if(((RenderingComponent*)(*it))->getDepth() == -1)
    			((RenderingComponent*)(*it))->render(graphicsManager);
    		else
    			renderQueue.push_back(((RenderingComponent*)(*it)));

		// Traverse the graph recursively
		for(std::set<SceneNode*>::iterator it = sceneNode->getChildren()->begin(); it != sceneNode->getChildren()->end(); it++)
			buildQueue(*it);
	}

	void RenderingSystem::render()
	{
		graphicsManager->setDepthTest(false);
		renderQueue.sort(RenderingSystem::sort); // Sort using RenderingSystem::sort()
		while(!renderQueue.empty())
		{
			renderQueue.front()->render(graphicsManager);
			renderQueue.pop_front();
		}
		graphicsManager->setDepthTest(true);
	}

	bool RenderingSystem::sort(RenderingComponent *l, RenderingComponent *r)
	{
		return (*l) < (*r);
	}
}
