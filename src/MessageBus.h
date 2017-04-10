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
        void registerListener(const std::function<const Message*(const Message*)> listener);
        void removeListener(const std::function<const Message*(const Message*)> listener);

        // Messages
        void sendMessage(const Message * const message) const;
    private:
        std::vector<std::function<const Message*(const Message*)>> listeners;
    };
}

#endif
