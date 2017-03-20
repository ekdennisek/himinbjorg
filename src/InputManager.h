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

        InputManager(GLFWwindow* window, MessageBus *messageBus);
        virtual ~InputManager();

        //Keyboard input
        static void charInputCallback(GLFWwindow* window, unsigned int key);
        static void keyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        bool getKeyState(Key key);

        // Mouse input
        static void mouseMovementCallback(GLFWwindow *window, double x, double y);
        static void mouseClickCallback(GLFWwindow *window, int button, int action, int mods);
    private:
        GLFWwindow *window;
        MessageBus *messageBus;
    };
}

#endif
