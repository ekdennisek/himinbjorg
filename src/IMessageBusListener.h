#ifndef IMESSAGEBUSLISTENER_H
#define IMESSAGEBUSLISTENER_H

namespace Himinbjorg
{
    // Forward declaration
    class Message;

    class IMessageBusListener
    {
    public:
        virtual Message* onMessage(Message *msg) = 0;
    };
}

#endif