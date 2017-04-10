#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <string>

namespace Himinbjorg
{
    // Forward declaration
    class SceneNode;

    class SceneManager
    {
    public:
        SceneManager();
        virtual ~SceneManager();

        SceneNode *getSceneRoot() const;
        const SceneNode *findNode(const std::string identifier);
    private:
        const SceneNode *search(const SceneNode * const sceneNode, const std::string identifier) const;

        SceneNode *sceneRoot;
    };
}

#endif
