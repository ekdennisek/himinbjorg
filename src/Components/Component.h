#ifndef COMPONENT_H
#define COMPONENT_H

namespace Himinbjorg
{
    // Forward declaration
    class SceneNode;

    enum ComponentType {
    	TRANSFORM_COMPONENT,
    	RENDERING_COMPONENT,
		RENDERING_DATA_COMPONENT,	// TODO Remove
		GUI_COMPONENT,	// TODO Remove
		BUTTON_COMPONENT,	// TODO Remove
		CLICKABLE_COMPONENT,
		INPUT_COMPONENT,
		CAMERA_COMPONENT,
		BEHAVIOR_COMPONENT,
		GEOMETRY_COMPONENT
    };

    class Component
    {
    public:

        Component(ComponentType componentType);
        virtual ~Component();

        void setParent(SceneNode *parent);
        SceneNode *getParent();
        ComponentType getComponentType();
    protected:
        SceneNode *parent;
        ComponentType componentType;
    };
}

#endif
