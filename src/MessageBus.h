#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include <vector>
#include <functional>

namespace Himinbjorg
{
    // Forward declarations
    class IMessageBusListener;
    class Message;

    class MessageBus
    {
    public:
        MessageBus();
        virtual ~MessageBus();

        // Message listeners
        void registerListener(IMessageBusListener *listener);
        void removeListener(IMessageBusListener *listener);

        // Messages
        void sendMessage(Message *message) const;
    private:
        std::vector<IMessageBusListener*> listeners;
    };
}

#endif
