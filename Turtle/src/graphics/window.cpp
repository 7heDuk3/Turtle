#include "window.h"

namespace turtle {
	namespace graphics {

		void window_size_cb(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		Window::Window(const char *name, int width, int height)
		{
			m_Name = name;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();

			for (int i = 0; i < MAX_KEYS; ++i)
			{
				m_Keys[i] = false;
			}
			
			for (int i = 0; i < MAX_BUTTONS; ++i)
			{
				m_MouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_size_cb);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);

			std::cout << "OpenGL " << glGetString(GL_VERSION);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			return true;
		}

		bool Window::isKeyPressed(unsigned int keycode)
		{
			// TODO: Log this!
			if (keycode >= MAX_KEYS)
				return false;

			return m_Keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button)
		{
			// TODO: Log this!
			if (button >= MAX_BUTTONS)
				return false;

			return m_MouseButtons[button];
		}

		void Window::getMousePosition(double& x, double& y) const
		{
			x = m_MX;
			y = m_MY;
		}


		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
			{
				std::cout << "OpenGL Error: " << error << std::endl;
			}

			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glViewport(0, 0, m_Width, m_Height);
			glfwSwapBuffers(m_Window);
		}
		
		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action == GLFW_PRESS;
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MX = xpos;
			win->m_MY = ypos;
		}
	}
}