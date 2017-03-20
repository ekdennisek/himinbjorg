#ifndef BEHAVIORCOMPONENT_H
#define BEHAVIORCOMPONENT_H

#include "Component.h"

namespace Himinbjorg
{
    class BehaviorComponent : public Component
    {
    public:
    	BehaviorComponent();
        virtual ~BehaviorComponent();

        virtual void update() = 0;
    };
}

#endif
