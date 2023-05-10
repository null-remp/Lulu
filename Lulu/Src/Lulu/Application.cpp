#include "Application.hpp"

#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"

Lulu::Application::Application()
{
}

Lulu::Application::~Application()
{
}

void Lulu::Application::Run()
{
	WindowResizeEvent e(1280, 720);
	LU_CORE_TRACE(e);

	while (true)
	{

	}
}
