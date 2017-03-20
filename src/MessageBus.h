#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include "Message.h"
#include <vector>
#include <functional>

namespace Himinbjorg
{
    class MessageBus
    {
    public:
        MessageBus();
        virtual ~MessageBus();

        // Message listeners
        void registerListener(std::function<Message*(Message*)> listener);
        void removeListener(std::function<Message*(Message*)> listener);

        // Messages
        void sendMessage(Message* message);
    private:
        std::vector<std::function<Message*(Message*)>> listeners;
    };
}

#endif
