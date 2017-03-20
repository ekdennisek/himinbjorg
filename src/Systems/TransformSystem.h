#ifndef TRANSFORMSYSTEM_H
#define TRANSFORMSYSTEM_H

namespace Himinbjorg
{
    // Forward definitions
    class TransformComponent;
    class SceneNode;

    /**
     * Responsible for traversing the scene graph and updating transform components.
     */

	class TransformSystem
	{
	public:
		TransformSystem();
		virtual ~TransformSystem();

		void recalculateMatrices(SceneNode *sceneNode, TransformComponent *parentTransform);
	};
}
#endif
