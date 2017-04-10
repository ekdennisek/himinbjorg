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
		RenderingSystem(GraphicsManager * const graphicsManager);
		virtual ~RenderingSystem();

		void buildQueue(const SceneNode * const sceneNode);
		void render();
		static bool sort(const RenderingComponent * const l, const RenderingComponent * const r);
	private:
		GraphicsManager *graphicsManager;
		std::list<RenderingComponent*> renderQueue;
	};
}

#endif
