#include "Component.h"

namespace Himinbjorg
{
    Component::Component(const ComponentType componentType)
    {
        this->componentType = componentType;
        parent = nullptr;
    }

    Component::~Component()
    {
    }

    void Component::setParent(SceneNode * const parent)
    {
    	this->parent = parent;
    }

    SceneNode *Component::getParent() const
    {
    	return parent;
    }

    ComponentType Component::getComponentType() const
    {
    	return componentType;
    }
}
