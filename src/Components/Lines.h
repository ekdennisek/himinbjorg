#ifndef LINES_H
#define LINES_H

#include "GeometryComponent.h"

namespace Himinbjorg
{
	class Lines : public GeometryComponent
	{
	public:
		Lines(GLfloat *vertexBuffer, int nrOfLines);
		virtual ~Lines();

		int getNrOfLines();
	private:
		int nrOfLines;
	};
}

#endif
