#pragma once

#ifdef LU_PLATFORM_WINDOWS

extern Lulu::Application* Lulu::CreateApplication();

int main(int argc, char** argv)
{
	Lulu::Log::Init();
	LU_CORE_WARN("Initialized Log!");
	int a = 12;
	LU_APP_INFO("Hello App! Var={0}", a);


	auto sandbox = Lulu::CreateApplication();
	sandbox->Run();
	delete sandbox;

	return 0;
}

#endif // LU_PLATFORM_WINDOWS
