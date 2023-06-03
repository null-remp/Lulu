#pragma once

#include "Lulu/Core.hpp"
#include "Lulu/Events/Event.hpp"

namespace Lulu
{
	class LULU_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");

		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return n_DebugName; }

	private:
		std::string n_DebugName;
	};
}