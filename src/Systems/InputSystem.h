#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

namespace Himinbjorg
{
    // Forward declaration
    class SceneNode;

    /**
     * Responsible for traversing the scene graph and updating input components.
     */

	class InputSystem
	{
	public:
		InputSystem(SceneNode *sceneRoot);
		virtual ~InputSystem();

		void update();
	private:
		void traverse(SceneNode *sceneNode);

		SceneNode *sceneRoot;
	};
}

#endif
