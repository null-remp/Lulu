#include "Lulu.hpp"


#include <iostream>

class Sandbox : public Lulu::Application
{
public:
	Sandbox()
	{
		std::cout << "Hello there" << std::endl;
	}

	~Sandbox()
	{

	}
};

Lulu::Application* Lulu::CreateApplication()
{
	return new Sandbox();
}