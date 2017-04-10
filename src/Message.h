#ifndef MESSAGE_H
#define MESSAGE_H

namespace Himinbjorg
{
    class Message
    {
	public:
		enum Type { KEYBOARD_INPUT, MOUSE_INPUT, GUI_INPUT };
		enum SubType { KEY_DOWN, KEY_UP, CHARACTER, KEY_PRESS, KEY_RELEASE, KEY_REPEAT,
		               MOUSE_MOVE, MOUSE_CLICK, MOUSE_RELEASE,
		               NONE };

        Message(const Type type, const SubType subType, const char * const data);
        virtual ~Message();

        Type type;
        SubType subType;
        const char *data;
    };
}

#endif
