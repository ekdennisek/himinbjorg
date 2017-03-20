#include "Component.h"

namespace Himinbjorg
{
    Component::Component(ComponentType componentType)
    {
        this->componentType = componentType;
        parent = nullptr;
    }

    Component::~Component()
    {
    }

    void Component::setParent(SceneNode *parent)
    {
    	this->parent = parent;
    }

    SceneNode *Component::getParent()
    {
    	return parent;
    }

    ComponentType Component::getComponentType()
    {
    	return componentType;
    }
}
