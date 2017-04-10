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
		OrthoPlane(const float left, const float top, const float width, const float height);
		virtual ~OrthoPlane();

		// Getters for the plane properties
		int getLeft() const;
		int getTop() const;
		int getWidth() const;
		int getHeight() const;
	private:
		GLfloat left;
		GLfloat top;
		GLfloat width;
		GLfloat height;
	};
}

#endif
