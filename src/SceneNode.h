#ifndef SCENENODE_H
#define SCENENODE_H

#include "Components/Component.h"
#include <vector>
#include <set>
#include <string>

namespace Himinbjorg
{
    class SceneNode
    {
    public:
        SceneNode(std::string identifier);
        virtual ~SceneNode();

        // Add, remove and find components
        void addComponent(Component *component);
        void removeComponent(Component *component);
        std::vector<Component*> findComponents(ComponentType type);

        // Add, remove and get a list of the children
        void addChild(SceneNode *child);
        void removeChild(SceneNode *child);
        std::set<SceneNode*> *getChildren();

        // Setters
        void setParent(SceneNode *parent);
        void setIdentifier(std::string identifier);

        // Getters
        SceneNode *getParent() const;
        std::string getIdentifier() const;
    private:
        SceneNode *parent;
        std::string identifier;
        std::vector<Component*> components;
        std::set<SceneNode*> children;
    };
}

#endif
