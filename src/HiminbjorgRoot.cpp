#include "HiminbjorgRoot.h"
#include "MessageBus.h"
#include "SceneManager.h"
#include "Systems/RenderingSystem.h"
#include "Systems/InputSystem.h"
#include "Systems/CameraSystem.h"
#include "Systems/BehaviorSystem.h"
#include "Systems/TransformSystem.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "ResourceManager.h"
#include <iostream>
#include <cstddef>
#include <ctime>

namespace Himinbjorg
{
    HiminbjorgRoot::HiminbjorgRoot()
    {
    	// Core engine components (make sure to initialize them in the correct order)
        messageBus = new MessageBus();
        graphicsManager = new GraphicsManager();
        inputManager = new InputManager(graphicsManager->getWindow(), messageBus);
        physicsManager = new PhysicsManager(messageBus, graphicsManager);
        sceneManager = new SceneManager();

        // ECS systems
        renderingSystem = new RenderingSystem(graphicsManager);
        inputSystem = new InputSystem(sceneManager->getSceneRoot());
        cameraSystem = new CameraSystem(graphicsManager);
        behaviorSystem = new BehaviorSystem();
        transformSystem = new TransformSystem();
    }

    HiminbjorgRoot::~HiminbjorgRoot()
    {
        // Delete ECS systems in reverse order
        if(transformSystem) delete transformSystem;
        if(behaviorSystem) delete behaviorSystem;
        if(cameraSystem) delete cameraSystem;
        if(inputSystem) delete inputSystem;
        if(renderingSystem) delete renderingSystem;

    	// Delete core engine components in reverse creation order
        if(sceneManager) delete sceneManager;
        if(physicsManager) delete physicsManager; // Must come after sceneManager, since some scene objects need to unregister from collisions
        if(inputManager) delete inputManager;
        if(graphicsManager) delete graphicsManager;
        if(messageBus) delete messageBus;
        ResourceManager::getInstance().cleanup();
    }

    void HiminbjorgRoot::run()
    {
    	GLFWwindow *window = graphicsManager->getWindow();
    	SceneNode *sceneRoot = sceneManager->getSceneRoot();

        // FPS
        double lastTime  = 0;
        int frameCounter = 0;

        // Time stepping
        double t = 0;
        const double dt = 0.1;
        timespec spec;
        clock_gettime(CLOCK_REALTIME, &spec);
        double currentTime = spec.tv_sec * 1.0e3 + spec.tv_nsec / 1.0e6; // Millisecond resolution should be enough
        double accumulator = 0;

        while(!glfwWindowShouldClose(window))
        {
        	// See http://gafferongames.com/game-physics/fix-your-timestep/ for explanation
        	clock_gettime(CLOCK_REALTIME, &spec);
        	double newTime = spec.tv_sec * 1.0e3 + spec.tv_nsec / 1.0e6;
        	double frameTime = newTime - currentTime;
        	currentTime = newTime;
        	accumulator += frameTime;

        	if(currentTime - lastTime > 1000)
        	{
        		std::cout << "FPS: " << frameCounter << std::endl;
        		lastTime = currentTime;
        		frameCounter = 0;
        	} else
        		frameCounter++;

            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            inputSystem->update(); // TODO: Pass sceneRoot as a parameter here instead of in constructor?
            while(accumulator >= dt)
            {
            	// Update the systems which is dependent on time (i.e. behavior, physics components) using dt
            	physicsManager->update(dt);
            	accumulator -= dt;
            	t += dt;
            }
            behaviorSystem->update(sceneRoot);
            transformSystem->recalculateMatrices(sceneRoot, NULL);
            cameraSystem->update(sceneRoot);
            renderingSystem->buildQueue(sceneRoot);
            renderingSystem->render();
            glfwSwapBuffers(window);
        }

		GLenum errorCode = GL_NO_ERROR;
		while((errorCode = glGetError()) != GL_NO_ERROR)
			std::cout << "HiminbjorgRoot::run(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
    }

    MessageBus *HiminbjorgRoot::getMessageBus() const
    {
        return messageBus;
    }

    GraphicsManager *HiminbjorgRoot::getGraphicsManager() const
    {
    	return graphicsManager;
    }

    SceneManager *HiminbjorgRoot::getSceneManager() const
    {
    	return sceneManager;
    }

    PhysicsManager *HiminbjorgRoot::getPhysicsManager() const
    {
    	return physicsManager;
    }

    InputManager *HiminbjorgRoot::getInputManager() const
    {
    	return inputManager;
    }
}
