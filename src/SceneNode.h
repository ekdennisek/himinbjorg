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

        // Skriv en setParent som anropas av föräldern när man anropar addChild()
        void setParent(SceneNode *parent);

        // Add, remove and get a list of the children
        void addChild(SceneNode *child);
        void removeChild(SceneNode *child);
        std::set<SceneNode*> *getChildren();

        SceneNode *getParent();
        std::string getIdentifier();
    private:
        SceneNode *parent;
        std::string identifier;
        std::vector<Component*> components;
        std::set<SceneNode*> children;
    };
}

#endif