#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include "Component.h"
#include <glm/mat4x4.hpp>

namespace Himinbjorg
{
    // Forward declaration
    class SceneNode;
    class GraphicsManager;

	class CameraComponent : public Component
	{
	public:
		CameraComponent(int width, int height);
		virtual ~CameraComponent();

		void update(GraphicsManager *graphicsManager);

		void setActive(bool active);

		glm::mat4 *getProjectionMatrix();
		glm::mat4 *getViewMatrix();
		bool isActive();
	private:
		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;
		bool active;
	};

}

#endif
