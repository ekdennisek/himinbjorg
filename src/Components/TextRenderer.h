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
		TextRenderer(const Text * const text, const Material * const material, const int depth);
		virtual ~TextRenderer();

		void render(const GraphicsManager * const graphicsManager);
	private:
		const Text *text;
	};
}

#endif
