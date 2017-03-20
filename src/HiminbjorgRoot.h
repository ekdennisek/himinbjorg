#ifndef HIMINBJORGROOT_H
#define HIMINBJORGROOT_H

namespace Himinbjorg
{
    // Forward declaration
    class GraphicsManager;
    class InputManager;
    class PhysicsManager;
    class ResourceManager;
    class MessageBus;
    class SceneManager;
    class RenderingSystem;
    class InputSystem;
    class CameraSystem;
    class BehaviorSystem;
    class TransformSystem;
    class OrthoPlaneRenderingSystem;

    class HiminbjorgRoot
    {
    public:
        HiminbjorgRoot();
        virtual ~HiminbjorgRoot();

        void run();

        // Getters
        MessageBus *getMessageBus();
        GraphicsManager *getGraphicsManager();
        SceneManager *getSceneManager();
        PhysicsManager *getPhysicsManager();
        InputManager *getInputManager();
    protected:
        // Core components
        GraphicsManager *coreDraw;
        InputManager *coreInput;
        PhysicsManager *corePhysics;
        SceneManager *sceneManager;
        MessageBus *messageBus;

        // ECS systems
        RenderingSystem *renderingSystem;
        InputSystem *inputSystem;
        CameraSystem *cameraSystem;
        BehaviorSystem *behaviorSystem;
        TransformSystem *transformSystem;
    };
}

#endif
