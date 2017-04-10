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

    SceneNode *SceneManager::getSceneRoot()
    {
        return sceneRoot;
    }

    SceneNode *SceneManager::findNode(std::string identifier)
    {
    	return search(sceneRoot, identifier);
    }

    SceneNode *SceneManager::search(SceneNode *sceneNode, std::string identifier)
    {
    	if(sceneNode->getIdentifier().compare(identifier) == 0)
    		return sceneNode;

    	std::set<SceneNode*> *children = sceneNode->getChildren();
    	for(std::set<SceneNode*>::iterator it = children->begin(); it != children->end(); it++)
    	{
    		SceneNode *currentChild = search(*it, identifier);
    		if(currentChild && currentChild->getIdentifier().compare(identifier) == 0)
    			return *it;
    	}

    	return nullptr;
    }
}
