#include "SceneNode.h"
#include "Components/TransformComponent.h"

namespace Himinbjorg
{
    SceneNode::SceneNode(std::string identifier)
    {
    	TransformComponent *transform = new TransformComponent();
    	addComponent(transform);

    	this->identifier = identifier;
    	parent = nullptr;
    }

    SceneNode::~SceneNode()
    {
    	// Release every component
    	std::vector<Component*>::iterator itComponents = components.begin();
    	while(itComponents != components.end())
    	{
    		delete *itComponents;
    		itComponents++;
    	}
    	components.clear();

        // Release every child node
    	for(std::set<SceneNode*>::iterator it = children.begin(); it != children.end(); it++)
    		delete (*it);
    	children.clear();
    }

    /*
     * Methods for manipulating components
     */

    void SceneNode::addComponent(Component *component)
    {
        component->setParent(this);
        components.push_back(component);
    }

    void SceneNode::removeComponent(Component *component)
    {
    	for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); it++)
    		if(*it == component)
    			components.erase(it);
    }

    std::vector<Component*> SceneNode::findComponents(ComponentType type)
    {
    	std::vector<Component*> result;

    	std::vector<Component*>::iterator iter = components.begin();

    	for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); it++)
    		if((*it)->getComponentType() == type)
    			result.push_back(*it);

    	return result;
    }

    /*
     * Methods for manipulating child nodes
     */

    void SceneNode::addChild(SceneNode *child)
    {
    	children.insert(child);
    	child->setParent(this);
    }

    void SceneNode::removeChild(SceneNode *child)
    {
    	std::set<SceneNode*>::iterator it = children.find(child);
    	if(it != children.end())
    		children.erase(it);
    }

    std::set<SceneNode*> *SceneNode::getChildren()
    {
    	return &children;
    }
    
    void SceneNode::setParent(SceneNode *parent)
    {
        this->parent = parent;
    }

    void SceneNode::setIdentifier(std::string identifier)
    {
        this->identifier = identifier;
    }

    SceneNode *SceneNode::getParent() const
    {
    	return parent;
    }

    std::string SceneNode::getIdentifier() const
    {
    	return identifier;
    }
}
