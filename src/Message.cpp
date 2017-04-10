#include "Message.h"

namespace Himinbjorg
{
    Message::Message(const Type type, const SubType subType, const char * const data)
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
