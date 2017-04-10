#include "SceneManager.h"
#include "SceneNode.h"

namespace Himinbjorg
{
    SceneManager::SceneManager()
    {
        sceneRoot = new SceneNode("rootNode");
    }

    SceneManager::~SceneManager()
    {
        if(sceneRoot) delete sceneRoot;
    }

    SceneNode *SceneManager::getSceneRoot() const
    {
        return sceneRoot;
    }

    const SceneNode *SceneManager::findNode(const std::string identifier)
    {
    	return search(sceneRoot, identifier);
    }

    const SceneNode *SceneManager::search(const SceneNode * const sceneNode, const std::string identifier) const
    {
    	if(sceneNode->getIdentifier().compare(identifier) == 0)
    		return sceneNode;

    	const std::set<SceneNode*> *children = sceneNode->getChildren();
    	for(std::set<SceneNode*>::iterator it = children->begin(); it != children->end(); it++)
    	{
    		const SceneNode *currentChild = search(*it, identifier);
    		if(currentChild && currentChild->getIdentifier().compare(identifier) == 0)
    			return *it;
    	}

    	return nullptr;
    }
}
