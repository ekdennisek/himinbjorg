#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "Component.h"
#include <glm/mat4x4.hpp>

namespace Himinbjorg
{
    class TransformComponent : public Component
    {
    public:
        TransformComponent();
        TransformComponent(float* position, float* rotations, float scale);
        virtual ~TransformComponent();

        void recalculate(TransformComponent *parentTransform);
        void makeDirty();

        // Setters
        void setPosition(float *position);
        void setRotations(float *rotations);
        void setScale(float scale);

        // Getters
        float *getPosition();
        float *getRotations();
        float getScale();
        bool isDirty();
        glm::mat4 *getTransformtionMatrix();
    private:
        void calculateMatrix();

        float position[3]; // x, y, z
        float rotations[3]; // yaw, pitch, roll
        float scale;
        bool dirty;
        glm::mat4 transformationMatrix;
    };
}

#endif
