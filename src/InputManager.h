#ifndef COREINPUT_H
#define COREINPUT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Himinbjorg
{
    // Forward declaration
    class MessageBus;

    class InputManager
    {
    public:
    	enum Key { KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G,
    	   	       KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M, KEY_N,
    			   KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U,
    			   KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,
    	           KEY_ESC };

        InputManager(GLFWwindow * const window, const MessageBus * const messageBus);
        virtual ~InputManager();

        //Keyboard input
        static void charInputCallback(GLFWwindow * const window, const unsigned int key);
        static void keyInputCallback(GLFWwindow * const window, const int key, const int scancode, const int action, const int mods);
        bool getKeyState(const Key key) const;

        // Mouse input
        static void mouseMovementCallback(GLFWwindow * const window, const double x, const double y);
        static void mouseClickCallback(GLFWwindow * const window, const int button, const int action, const int mods);
    private:
        GLFWwindow *window;
        const MessageBus *messageBus;
    };
}

#endif
