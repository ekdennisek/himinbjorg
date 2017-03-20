#include "TextRenderer.h"
#include "../GraphicsManager.h"

namespace Himinbjorg
{
	TextRenderer::TextRenderer(std::string text, int size, GLfloat left, GLfloat top, Material *material, int depth)
	: RenderingComponent(material, depth)
	{
		this->text = text;
		this->size = size;
		this->left = left;
		this->top = top;

		glBindVertexArray(vao);
		    glBindBuffer(GL_ARRAY_BUFFER, vbo);
		    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*4*6, nullptr, GL_DYNAMIC_DRAW);
		    glEnableVertexAttribArray(0);
		    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*4, 0);
		    glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	TextRenderer::~TextRenderer()
	{
	}

	void TextRenderer::render(GraphicsManager *graphicsManager)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		graphicsManager->drawText(vao, vbo, text, material,  left, top, size);
		glDisable(GL_BLEND);
	}
}
