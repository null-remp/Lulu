#pragma once

#include "Event.hpp"

#include <sstream>

namespace Lulu
{
	class LULU_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned width, unsigned height) : m_Width(width), m_Height(height) {}

		inline unsigned GetWidth() const { return m_Width; }
		inline unsigned GetHight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned m_Width, m_Height;
	};

	class LULU_API WindowCloseEvent : public Event
	{
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class LULU_API AppTickEvent : public Event
	{
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class LULU_API AppUpdateEvent : public Event
	{
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class LULU_API AppRenderEvent : public Event
	{
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}