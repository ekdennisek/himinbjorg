#include "InputManager.h"
#include "Message.h"
#include "MessageBus.h"
#include <iostream>
#include <unicode/unistr.h> // ICU coding/decoding
#include <cstring> // memcpy

namespace Himinbjorg
{
    InputManager::InputManager(GLFWwindow* window, MessageBus *messageBus)
    {
        this->window = window;
        this->messageBus = messageBus;

        glfwSetWindowUserPointer(window, this);
        glfwSetCharCallback(window, (GLFWcharfun) &InputManager::charInputCallback);
        glfwSetKeyCallback(window, (GLFWkeyfun) &InputManager::keyInputCallback);
        glfwSetCursorPosCallback(window, &InputManager::mouseMovementCallback);
        glfwSetMouseButtonCallback(window, &InputManager::mouseClickCallback);

    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "CoreInput::CoreInput(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
    }

    InputManager::~InputManager()
    {
    }

    /*
     * Keyboard input
     */

    void InputManager::charInputCallback(GLFWwindow* window, unsigned int key)
    {
        // Since this is a static member function passed to a C API, perform a little magic!
        InputManager *instanceReference = (InputManager*) glfwGetWindowUserPointer(window); 

        // Convert from UTF-32 to UTF-8
        icu::UnicodeString unicode((UChar32)key);
        std::string utf8;
        unicode.toUTF8String(utf8);

        // Create a copy of string, used as the message data
        char *dataPointer = new char[utf8.size()];
        memcpy(dataPointer, utf8.c_str(), utf8.size());

        // Create a message and pass it to the message bus
        Message *msg = new Message(Message::KEYBOARD_INPUT, Message::CHARACTER, dataPointer);
        instanceReference->messageBus->sendMessage(msg);
    }

    void InputManager::keyInputCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
    	// Since this is a static member function passed to a C API, perform a little magic!
    	InputManager *instanceReference = (InputManager*) glfwGetWindowUserPointer(window);

    	Message::SubType subType;
    	if(action == GLFW_PRESS)
    		subType = Message::KEY_PRESS;
    	else if(action == GLFW_RELEASE)
    		subType = Message::KEY_RELEASE;
    	else if(action == GLFW_REPEAT)
    		subType = Message::KEY_REPEAT;

    	char *dataPointer = new char[sizeof(key)];
    	memcpy(dataPointer, &key, sizeof(key));

    	Message *msg = new Message(Message::KEYBOARD_INPUT, subType, dataPointer);
    	instanceReference->messageBus->sendMessage(msg);
    }

    bool InputManager::getKeyState(Key key)
    {
    	if(key == Key::KEY_A)
    		return (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS);
    	else if(key == Key::KEY_B)
    		return (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS);
    	else if(key == Key::KEY_C)
    		return (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS);
    	else if(key == Key::KEY_D)
    		return (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS);
    	else if(key == Key::KEY_S)
    		return (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS);
    	else if(key == Key::KEY_W)
    		return (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS);
    	else if(key == Key::KEY_ESC)
    		return (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS);

    	return false;
    }

    /*
     * Mouse input
     */

    void InputManager::mouseMovementCallback(GLFWwindow *window, double x, double y)
    {
        // Since this is a static member function passed to a C API, perform a little magic!
        InputManager *instanceReference = (InputManager*) glfwGetWindowUserPointer(window);

        // Create a copy of the data for the message
        double *dataPointer = new double[2];
        dataPointer[0] = x;
        dataPointer[1] = y;

        // Create a message and pass it to the bus
        Message *msg = new Message(Message::MOUSE_INPUT, Message::MOUSE_MOVE, (char*)dataPointer);
        instanceReference->messageBus->sendMessage(msg);
    }

    void InputManager::mouseClickCallback(GLFWwindow *window, int button, int action, int mods)
    {
    	// Since this is a static member function passed to a C API, perform a little magic!
    	InputManager *instanceReference = (InputManager*) glfwGetWindowUserPointer(window);

    	if(action == GLFW_PRESS)
    	{
			// Message data consists of ray origin and direction (world space)
			char *dataPointer = new char[1];
			if(button == GLFW_MOUSE_BUTTON_LEFT)
				dataPointer[0] = -1;
			else if(button == GLFW_MOUSE_BUTTON_RIGHT)
				dataPointer[0] = 1;

			Message *msg = new Message(Message::MOUSE_INPUT, Message::MOUSE_CLICK, (char*)dataPointer);
			instanceReference->messageBus->sendMessage(msg);
    	}
    }
}
