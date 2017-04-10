#ifndef PLANECOMPONENT_H
#define PLANECOMPONENT_H

#include "GeometryComponent.h"
#include <string>
#include <GL/glew.h>

namespace Himinbjorg
{
	class OrthoPlane : public GeometryComponent
	{
	public:
		OrthoPlane(float left, float top, float width, float height);
		virtual ~OrthoPlane();

		// Getters for the plane properties
		int getLeft();
		int getTop();
		int getWidth();
		int getHeight();
	private:
		GLfloat left;
		GLfloat top;
		GLfloat width;
		GLfloat height;
	};
}

#endif
