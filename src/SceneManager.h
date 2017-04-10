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

        SceneNode *getSceneRoot();
        SceneNode *findNode(std::string identifier);
    private:
        SceneNode *search(SceneNode *sceneNode, std::string identifier);

        SceneNode *sceneRoot;
    };
}

#endif
