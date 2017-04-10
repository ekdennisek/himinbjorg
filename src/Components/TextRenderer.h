#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include "RenderingComponent.h"

namespace Himinbjorg
{
    // Forward declaration
    class Material;
    class Text;

	class TextRenderer : public RenderingComponent
	{
	public:
		TextRenderer(Text *text, Material *material, int depth);
		virtual ~TextRenderer();

		void render(GraphicsManager *graphicsManager);
	private:
		Text *text;
	};
}

#endif
