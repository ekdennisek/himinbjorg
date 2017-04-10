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

    void SceneNode::setParent(SceneNode *parent)
    {
    	this->parent = parent;
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

    std::vector<Component*> SceneNode::findComponents(ComponentType type) const
    {
    	std::vector<Component*> result;

    	for(std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); it++)
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

    const std::set<SceneNode*> *SceneNode::getChildren() const
    {
    	return &children;
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
