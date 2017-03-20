#include "Message.h"

namespace Himinbjorg
{
    Message::Message(Type type, SubType subType, char *data)
    {
        this->type = type;
        this->subType = subType;
        this->data = data;
    }

    Message::~Message()
    {
        if(data) delete[] data;
    }
}
