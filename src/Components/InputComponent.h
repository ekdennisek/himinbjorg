#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "Component.h"

namespace Himinbjorg
{
	class InputComponent : public Component
	{
	public:
		InputComponent();
		virtual ~InputComponent();

		virtual void readKeys() = 0;
	};
}

#endif
