#ifndef BEHAVIORSYSTEM_H
#define BEHAVIORSYSTEM_H

namespace Himinbjorg
{
    // Forward definition
    class SceneNode;

    /**
     * Responsible for traversing the scene graph and updating behavior components.
     */

	class BehaviorSystem
	{
	public:
		BehaviorSystem();
		virtual ~BehaviorSystem();

		void update(const SceneNode * const sceneNode);
	};
}
#endif
