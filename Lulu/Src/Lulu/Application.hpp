#pragma once

#include "Core.hpp"

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

	Application* CreateApplication();
}
