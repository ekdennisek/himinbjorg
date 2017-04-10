#include "TextRenderer.h"
#include "../GraphicsManager.h"
#include "Text.h"

namespace Himinbjorg
{
	TextRenderer::TextRenderer(const Text * const text, const Material * const material, const int depth)
	: RenderingComponent(material, depth)
	{
		this->text = text;
	}

	TextRenderer::~TextRenderer()
	{
	}

	void TextRenderer::render(const GraphicsManager * const graphicsManager)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		graphicsManager->drawText(text->getVao(), text->getVbo(), text->getText(), material,  text->getLeft(), text->getTop(), text->getSize());
		glDisable(GL_BLEND);
	}
}
