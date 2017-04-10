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
		CameraComponent(const int width, const int height);
		virtual ~CameraComponent();

		void update(GraphicsManager * const graphicsManager);

		void setActive(const bool active);

		const glm::mat4 *getProjectionMatrix() const;
		const glm::mat4 *getViewMatrix() const;
		bool isActive() const;
	private:
		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;
		bool active;
	};

}

#endif
