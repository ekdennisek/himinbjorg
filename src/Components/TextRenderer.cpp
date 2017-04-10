#include "TextRenderer.h"
#include "../GraphicsManager.h"
#include "Text.h"

namespace Himinbjorg
{
	TextRenderer::TextRenderer(Text *text, Material *material, int depth)
	: RenderingComponent(material, depth)
	{
		this->text = text;
	}

	TextRenderer::~TextRenderer()
	{
	}

	void TextRenderer::render(GraphicsManager *graphicsManager)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		graphicsManager->drawText(text->getVao(), text->getVbo(), text->getText(), material,  text->getLeft(), text->getTop(), text->getSize());
		glDisable(GL_BLEND);
	}
}
