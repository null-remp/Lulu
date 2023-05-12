#include "lupch.hpp"

#include "Application.hpp"

#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"

#include "GLFW/glfw3.h"

Lulu::Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());
}

Lulu::Application::~Application()
{
}

void Lulu::Application::Run()
{
	while (m_Running)
	{
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT); 
		m_Window->OnUpdate();
	}
}
