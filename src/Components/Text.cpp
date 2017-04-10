#include "Text.h"

namespace Himinbjorg
{
	Text::Text(const std::string text, const int size, const GLfloat left, const GLfloat top)
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

	std::string Text::getText() const
	{
		return text;
	}

	int Text::getSize() const
	{
		return size;
	}

	GLfloat Text::getLeft() const
	{
		return left;
	}

	GLfloat Text::getTop() const
	{
		return top;
	}
} /* namespace Himinbjorg */
