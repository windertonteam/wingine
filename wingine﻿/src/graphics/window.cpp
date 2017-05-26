#include "window.h"
#include "../input/input.h"


using namespace core;
using namespace input;


namespace core { namespace graphics {

	Window::Window(const char* name, int width, int height)
	{
		this->name = name;
		this->width = width;
		this->height = height;
		if (!init())
			glfwTerminate();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "LOOOOL. Ti dawn chto li? GLFW IS not ok" << std::endl;
			glfwTerminate();
			return false;
		}

		window = glfwCreateWindow(width, height, name, NULL, NULL);
		Input input(window);


		glfwMakeContextCurrent(window);
		glfwSetWindowSizeCallback(window, resize_callback);
		glfwSetKeyCallback(window, key_callback);
		glfwSetMouseButtonCallback(window, button_callback);
		glfwSetCursorPosCallback(window, mouse_position_callback);


		if (glewInit() != GLEW_OK)
		{
			std::cout << "GLEW is not OK" << std::endl;
			return false;
		}

		return true;
	}

	void Window::update() 
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::render()
	{
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	void Window::mainLoop()
	{
		update();
		clear();
		render();
	}

	bool Window::closed()
	{
		return (glfwWindowShouldClose(window) == 1);
	}
	
	void resize_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

}}