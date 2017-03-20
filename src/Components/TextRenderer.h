#ifndef COMPONENTS_TEXTRENDERINGCOMPONENT_H
#define COMPONENTS_TEXTRENDERINGCOMPONENT_H

#include "RenderingComponent.h"
#include "GeometryComponent.h"
#include <GL/glew.h>
#include <string>

namespace Himinbjorg
{
    // Forward declaration
    class Material;

	class TextRenderer : public RenderingComponent, public GeometryComponent
	{
	public:
		TextRenderer(std::string text, int size, GLfloat left, GLfloat top, Material *material, int depth);
		virtual ~TextRenderer();

		void render(GraphicsManager *graphicsManager);
	private:
		std::string text;
		int size;
		GLfloat left;
		GLfloat top;
	};
}

#endif
