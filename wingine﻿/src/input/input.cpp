#include "input.h"

namespace core { namespace input {

	Input::Input(GLFWwindow* handle)
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			keys[i] = false;
		}

		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			buttons[i] = false;
		}

		glfwSetWindowUserPointer(handle, this);
	}

	Input::~Input()
	{

	}

	bool Input::isKeyPressed(int keyCode)
	{
		if (keyCode >= MAX_KEYS)
		{
			return false;
		}
		return keys[keyCode];
	}

	bool Input::isButtonPressed(int button)
	{
		if (button >= MAX_BUTTONS)
		{
			return false;
		}

		return buttons[button];
	}

	void Input::getMousePosition(double& x, double& y)
	{
		x = x;
		y = y;
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Input* input = (Input*)glfwGetWindowUserPointer(window);

		if (input->keys[key] = (action != GLFW_RELEASE))
		{
			std::cout << (GLchar)key << " is pressed" << std::endl;
		}
	}

	void button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Input* input = (Input*)glfwGetWindowUserPointer(window);

		if (input->buttons[button] = (action != GLFW_RELEASE))
		{
			std::cout << button << " is pressed" << std::endl;
		}
	}

	void mouse_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Input* input = (Input*)glfwGetWindowUserPointer(window);
		input->x = xpos;
		input->y = ypos;
		std::cout << "X: " << input->x << ", " << "Y:" << input->y << std::endl;
	}

}}