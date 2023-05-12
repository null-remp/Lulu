#pragma once

#include "lupch.hpp"

#include "Core.hpp"
#include "Events/Event.hpp"

namespace Lulu
{
	struct WindowProps
	{
		std::string Titel{};
		unsigned Width{ 0 };
		unsigned Height{ 0 };

		WindowProps(const std::string& title = "Lulu Engine",
			unsigned width = 1280, unsigned height = 720) : Titel(title), Width(width), Height(height) 
		{}
	};

	//Interface representing a desktop system based Window
	class LULU_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned GetWidth() const = 0;
		virtual unsigned GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps{});
	};
}