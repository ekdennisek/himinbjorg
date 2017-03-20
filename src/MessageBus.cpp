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

    void MessageBus::registerListener(std::function<Message*(Message*)> listener)
    {
        listeners.push_back(listener);
        std::cout << "MessageBus::registerListener(): Registering listener. " << listeners.size() << " listener(s) currently registered.\n";
    }

    void MessageBus::removeListener(std::function<Message*(Message*)> listener)
    {
        for(std::vector<std::function<Message*(Message*)>>::iterator it = listeners.begin(); listeners.size() && it != listeners.end(); it++)
            if(it->target<Message*(Message*)>() == listener.target<Message*(Message*)>())
                listeners.erase(it);

        std::cout << "MessageBus::registerListener(): Unregistering listener. " << listeners.size() << " listener(s) currently registered.\n";
    }

    void MessageBus::sendMessage(Message* message)
    {
        for(std::vector<std::function<Message*(Message*)>>::iterator it = listeners.begin(); message && it != listeners.end(); it++) {
            (*it)(message);
        }

        if(message) delete message;
    }
}
