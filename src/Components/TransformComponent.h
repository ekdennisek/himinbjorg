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
        TransformComponent(const float * const position, const float * const rotations, const float scale);
        virtual ~TransformComponent();

        void recalculate(TransformComponent * const parentTransform);
        void makeDirty();

        // Setters
        void setPosition(const float * const position);
        void setRotations(const float * const rotations);
        void setScale(const float scale);

        // Getters
        const float *getPosition() const;
        const float *getRotations() const;
        float getScale() const;
        bool isDirty() const;
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
