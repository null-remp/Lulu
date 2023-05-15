#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Window.hpp"

namespace Lulu
{
	class LULU_API Application
	{
	public:
		Application();
		virtual ~Application();

	public:
		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//Must be defined in Client
	Application* CreateApplication();
}
