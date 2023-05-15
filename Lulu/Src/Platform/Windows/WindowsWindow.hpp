#pragma once

#include "Lulu/Window.hpp"
#include "GLFW/glfw3.h"

namespace Lulu
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned GetWidth() const override { return m_Data.Width; }
		inline unsigned GetHeight() const override { return m_Data.Height; }

		//Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window{ nullptr };

		struct WindowData
		{
			std::string Title;
			unsigned Width{ 0 };
			unsigned Height{ 0 };
			bool VSync{ false };

			EventCallbackFn EventCallback;
		};
		
		WindowData m_Data;
	};
}