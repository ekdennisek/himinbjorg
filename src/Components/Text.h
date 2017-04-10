#ifndef TEXT_H_
#define TEXT_H_

#include "GeometryComponent.h"
#include <string>

namespace Himinbjorg
{
	class Text: public GeometryComponent
	{
	public:
		Text(const std::string text, const int size, const GLfloat left, const GLfloat top);
		virtual ~Text();

		std::string getText() const;
		int getSize() const;
		GLfloat getLeft() const;
		GLfloat getTop() const;
	private:
		std::string text;
		int size;
		GLfloat left;
		GLfloat top;
	};
} /* namespace Himinbjorg */

#endif /* COMPONENTS_TEXT_H_ */
