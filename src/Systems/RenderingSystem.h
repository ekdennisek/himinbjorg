#ifndef RENDERINGSYSTEM_H
#define RENDERINGSYSTEM_H

#include <list>

namespace Himinbjorg
{
    // Forward declaration
    class SceneNode;
    class GraphicsManager;
    class RenderingComponent;

    /**
     * Responsible for traversing the scene graph and rendering geometry.
     */

	class RenderingSystem
	{
	public:
		RenderingSystem(GraphicsManager *graphicsManager);
		virtual ~RenderingSystem();

		void buildQueue(SceneNode *sceneNode);
		void render();
		static bool sort(RenderingComponent *l, RenderingComponent *r);
	private:
		GraphicsManager *graphicsManager;
		std::list<RenderingComponent*> renderQueue;
	};
}

#endif
