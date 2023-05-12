#include "lupch.hpp"

#include "Log.hpp"

std::shared_ptr<spdlog::logger> Lulu::Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Lulu::Log::s_ClientLogger;

void Lulu::Log::Init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	
	s_CoreLogger = spdlog::stdout_color_mt("LULU");
	s_CoreLogger->set_level(spdlog::level::trace);

	s_ClientLogger = spdlog::stdout_color_mt("APP");
	s_ClientLogger->set_level(spdlog::level::trace);
}
