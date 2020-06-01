#include "TransformComponent.h"
#include "../SceneNode.h"
#include <cstring>
#include <GL/glew.h>
#include "../../lib/glm/glm/gtc/matrix_transform.hpp"

namespace Himinbjorg
{
    TransformComponent::TransformComponent()
    : Component(TRANSFORM_COMPONENT)
    {
    	memset(position, 0, 3*sizeof(GLfloat));
    	memset(rotations, 0, 3*sizeof(GLfloat));
    	scale = 1.0f;
    	dirty = true;
    }

    TransformComponent::TransformComponent(float* position, float* rotations, float scale)
    : Component(TRANSFORM_COMPONENT)
    {
        for(int i=0; i<3; i++)
        {
            this->position[i] = position[i];
            this->rotations[i] = rotations[i];
        }
        this->scale = scale;
        dirty = true;
    }

    TransformComponent::~TransformComponent()
    {
    }

    // Recursively make all children Transforms dirty
    void TransformComponent::makeDirty()
    {
    	dirty = true;
    	for(std::set<SceneNode*>::iterator it = parent->getChildren()->begin(); it != parent->getChildren()->end(); it++)
    	{
    		TransformComponent *transform = (TransformComponent*) (*it)->findComponents(TRANSFORM_COMPONENT).front();
    		transform->makeDirty();
    	}
    }

    void TransformComponent::recalculate(TransformComponent *parentTransform)
    {
    	dirty = false;
    	transformationMatrix = (*(parentTransform->getTransformtionMatrix()));
    	// Scaling
    	transformationMatrix = glm::scale(transformationMatrix,
    			                          glm::vec3(scale, scale, scale));
    	// Yaw
    	transformationMatrix = glm::rotate(transformationMatrix,
    			                           rotations[0],
										   glm::vec3(1.0f, 0.0f, 0.0f));
    	// Pitch
    	transformationMatrix = glm::rotate(transformationMatrix,
    			                           rotations[1],
										   glm::vec3(0.0f, 1.0f, 0.0f));
    	// Roll
    	transformationMatrix = glm::rotate(transformationMatrix,
    			                           rotations[2],
										   glm::vec3(0.0f, 0.0f, 1.0f));
    	// Translation
    	transformationMatrix = glm::translate(transformationMatrix,
    			                              glm::vec3(position[0], position[1], position[2]));
    }

    void TransformComponent::setPosition(float *position)
    {
        memcpy(this->position, position, 3*sizeof(GLfloat));
        dirty = true;
    }

    void TransformComponent::setRotations(float *rotations)
    {
    	memcpy(this->rotations, rotations, 3*sizeof(GLfloat));
    	dirty = true;
    }

    void TransformComponent::setScale(float scale)
    {
        this->scale = scale;
        dirty = true;
    }

    float *TransformComponent::getPosition()
    {
        return position;
    }

    float *TransformComponent::getRotations()
    {
        return rotations;
    }

    float TransformComponent::getScale()
    {
        return scale;
    }

    bool TransformComponent::isDirty()
    {
    	return dirty;
    }

    glm::mat4 *TransformComponent::getTransformtionMatrix()
    {
    	if(dirty)
    		calculateMatrix();

    	return &transformationMatrix;
    }

    void TransformComponent::calculateMatrix()
    {
    	// Identity
    	transformationMatrix = glm::mat4(1.0f);
    	// Scaling
    	transformationMatrix = glm::scale(transformationMatrix,
    			                          glm::vec3(scale, scale, scale));
    	// Yaw
    	transformationMatrix = glm::rotate(transformationMatrix,
    			                           rotations[0],
										   glm::vec3(1.0f, 0.0f, 0.0f));
    	// Pitch
    	transformationMatrix = glm::rotate(transformationMatrix,
    			                           rotations[1],
										   glm::vec3(0.0f, 1.0f, 0.0f));
    	// Roll
    	transformationMatrix = glm::rotate(transformationMatrix,
    			                           rotations[2],
										   glm::vec3(0.0f, 0.0f, 1.0f));
    	// Translation
    	transformationMatrix = glm::translate(transformationMatrix,
    			                              glm::vec3(position[0], position[1], position[2]));
    }
}
