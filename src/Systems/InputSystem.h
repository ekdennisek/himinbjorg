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
		InputSystem(const SceneNode * const sceneRoot);
		virtual ~InputSystem();

		void update();
	private:
		void traverse(const SceneNode * const sceneNode);

		const SceneNode *sceneRoot;
	};
}

#endif
