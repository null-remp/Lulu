#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"

namespace Lulu
{
	class LULU_API Application
	{
	public:
		Application();
		virtual ~Application();

	public:
		void Run();
	};

	//Must be defined in Client
	Application* CreateApplication();
}
