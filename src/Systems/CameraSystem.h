#ifndef CAMERASYSTEM_H
#define CAMERASYSTEM_H

namespace Himinbjorg
{
    // Forward declarations
    class SceneNode;
    class GraphicsManager;

    /**
     * Responsible for traversing the scene graph and updating camera components.
     */

	class CameraSystem
	{
	public:
		CameraSystem(GraphicsManager * const graphicsManager);
		virtual ~CameraSystem();

		void update(const SceneNode * const sceneNode);
	private:
		GraphicsManager *graphicsManager;
	};
}

#endif
