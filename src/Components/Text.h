#ifndef TEXT_H_
#define TEXT_H_

#include "GeometryComponent.h"
#include <string>

namespace Himinbjorg
{
	class Text: public GeometryComponent
	{
	public:
		Text(std::string text, int size, GLfloat left, GLfloat top);
		virtual ~Text();

		void setText(std::string text);
		void setSize(int size);
		void setLeft(GLfloat left);
		void setTop(GLfloat top);

		std::string getText();
		int getSize();
		GLfloat getLeft();
		GLfloat getTop();
	private:
		std::string text;
		int size;
		GLfloat left;
		GLfloat top;
	};
} /* namespace Himinbjorg */

#endif /* COMPONENTS_TEXT_H_ */
