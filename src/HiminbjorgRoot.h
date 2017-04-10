#ifndef HIMINBJORGROOT_H
#define HIMINBJORGROOT_H

namespace Himinbjorg
{
    // Forward declaration
    class GraphicsManager;
    class InputManager;
    class PhysicsManager;
    class MessageBus;
    class SceneManager;
    class RenderingSystem;
    class InputSystem;
    class CameraSystem;
    class BehaviorSystem;
    class TransformSystem;

    class HiminbjorgRoot
    {
    public:
        HiminbjorgRoot();
        virtual ~HiminbjorgRoot();

        void run();

        // Getters
        MessageBus *getMessageBus() const;
        GraphicsManager *getGraphicsManager() const;
        SceneManager *getSceneManager() const;
        PhysicsManager *getPhysicsManager() const;
        InputManager *getInputManager() const;
    protected:
        // Core components
        GraphicsManager *graphicsManager;
        InputManager *inputManager;
        PhysicsManager *physicsManager;
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
