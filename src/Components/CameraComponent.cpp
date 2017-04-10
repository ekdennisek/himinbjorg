#include "CameraComponent.h"
#include "../SceneNode.h"
#include "../GraphicsManager.h"
#include "TransformComponent.h"
#include <glm/gtc/matrix_transform.hpp> // perspective(), lookAt()

namespace Himinbjorg
{
	CameraComponent::CameraComponent(const int width, const int height)
	: Component(CAMERA_COMPONENT)
	{
		projectionMatrix = glm::perspective(45.0f, (float)width/(float)height, 0.1f, 100.0f);
		viewMatrix = glm::lookAt(glm::vec3(0.0f, 10.0f, 10.0f), // position
				                 glm::vec3(0.0f, 0.0f, 0.0f), // look at
								 glm::vec3(0.0f, 1.0f, 0.0f)); // up vector
		active = false;
	}

	CameraComponent::~CameraComponent()
	{
	}

	void CameraComponent::update(GraphicsManager * const graphicsManager)
	{
		// TODO: Store the view matrix and only update when needed?
		TransformComponent *transform = (TransformComponent*) parent->findComponents(TRANSFORM_COMPONENT).front();
		const float *position = transform->getPosition();
		viewMatrix = glm::lookAt(glm::vec3(position[0], position[1], position[2]), // position
				                 glm::vec3(position[0], position[1]-10, position[2]-10), // look at
								 glm::vec3(0.0f, 1.0f, 0.0f)); // up vector

		graphicsManager->setActiveCamera(&projectionMatrix, &viewMatrix);
	}

	void CameraComponent::setActive(const bool active)
	{
		this->active = active;
	}

	const glm::mat4 *CameraComponent::getProjectionMatrix() const
	{
		return &projectionMatrix;
	}

	const glm::mat4 *CameraComponent::getViewMatrix() const
	{
		return &viewMatrix;
	}

	bool CameraComponent::isActive() const
	{
		return active;
	}
}
