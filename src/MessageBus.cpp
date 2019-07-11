#include "MessageBus.h"
#include "Message.h"
#include "IMessageBusListener.h"
#include <iostream>

namespace Himinbjorg
{
    MessageBus::MessageBus()
    {
    }

    MessageBus::~MessageBus()
    {
    }

    void MessageBus::registerListener(IMessageBusListener *listener)
    {
        listeners.push_back(listener);
        std::cout << "MessageBus::registerListener(): Registering listener. " << listeners.size() << " listener(s) currently registered.\n";
    }

    void MessageBus::removeListener(IMessageBusListener *listener)
    {
        // For every registered message listener
        for(auto it = listeners.begin(); it != listeners.end(); it++) {
            // If the current std::function::target is the same as the requested
            if((*it) == listener) {
                // Remove it from the subscribed listener list
                listeners.erase(it);

                std::cout << "MessageBus::registerListener(): Unregistering listener. " << listeners.size() << " listener(s) currently registered.\n";
                return;
            }
        }
    }

    void MessageBus::sendMessage(Message* message) const
    {
        for(auto it = listeners.begin(); message && it != listeners.end(); it++) {
            (*it)->onMessage(message);
        }

        if(message) delete message;
    }
}
