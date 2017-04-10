#include "Text.h"

namespace Himinbjorg
{
	Text::Text(std::string text, int size, GLfloat left, GLfloat top)
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

	Text::~Text()
	{
	}

	std::string Text::getText()
	{
		return text;
	}

	int Text::getSize()
	{
		return size;
	}

	GLfloat Text::getLeft()
	{
		return left;
	}

	GLfloat Text::getTop()
	{
		return top;
	}
} /* namespace Himinbjorg */
