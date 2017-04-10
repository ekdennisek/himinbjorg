#ifndef LINES_H
#define LINES_H

#include "GeometryComponent.h"

namespace Himinbjorg
{
	class Lines : public GeometryComponent
	{
	public:
		Lines(const GLfloat * const vertexBuffer, const int nrOfLines);
		virtual ~Lines();

		int getNrOfLines() const;
	private:
		int nrOfLines;
	};
}

#endif
