#include "Lulu.hpp"

class ExampleLayer : public Lulu::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		LU_CORE_INFO("ExapleLayer::Update");
	}

	void OnEvent(Lulu::Event& event) override
	{
		LU_CORE_TRACE("{0}", event);
	}
};


class Sandbox : public Lulu::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Lulu::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Lulu::Application* Lulu::CreateApplication()
{
	return new Sandbox();
}