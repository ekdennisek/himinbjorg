#include "MessageBus.h"
#include <iostream>

namespace Himinbjorg
{
    MessageBus::MessageBus()
    {
    }

    MessageBus::~MessageBus()
    {
    }

    void MessageBus::registerListener(const std::function<const Message*(const Message*)> listener)
    {
        listeners.push_back(listener);
        std::cout << "MessageBus::registerListener(): Registering listener. " << listeners.size() << " listener(s) currently registered.\n";
    }

    void MessageBus::removeListener(const std::function<const Message*(const Message*)> listener)
    {
        for(std::vector<std::function<const Message*(const Message*)>>::iterator it = listeners.begin(); listeners.size() && it != listeners.end(); it++)
            if(it->target<const Message*(const Message*)>() == listener.target<const Message*(const Message*)>())
                listeners.erase(it);

        std::cout << "MessageBus::registerListener(): Unregistering listener. " << listeners.size() << " listener(s) currently registered.\n";
    }

    void MessageBus::sendMessage(const Message * const message) const
    {
        for(std::vector<std::function<const Message*(const Message*)>>::const_iterator it = listeners.begin(); message && it != listeners.end(); it++) {
            (*it)(message);
        }

        if(message) delete message;
    }
}
