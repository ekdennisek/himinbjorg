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
		OrthoPlane(GLfloat left, GLfloat top, GLfloat width, GLfloat height);
		virtual ~OrthoPlane();

		// Setters for the plane propertis
		void setLeft(GLfloat left);
		void setTop(GLfloat top);
		void setWidth(GLfloat width);
		void setHeight(GLfloat height);

		// Getters for the plane properties
		GLfloat getLeft();
		GLfloat getTop();
		GLfloat getWidth();
		GLfloat getHeight();
	private:
		void updateVertexBuffer();
		void updateVbo();

		GLfloat vertexBuffer[30];
		GLfloat left;
		GLfloat top;
		GLfloat width;
		GLfloat height;
	};
}

#endif
