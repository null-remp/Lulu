#pragma once

#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Lulu
{
	class LULU_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

/*
* Core log macros
*/
#define LU_CORE_TRACE(...)		::Lulu::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LU_CORE_INFO(...)		::Lulu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LU_CORE_WARN(...)		::Lulu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LU_CORE_ERROR(...)		::Lulu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LU_CORE_CRITICAL(...)	::Lulu::Log::GetCoreLogger()->critical(__VA_ARGS__)

/*
* Client log macros
*/
#define LU_APP_TRACE(...)		::Lulu::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LU_APP_INFO(...)		::Lulu::Log::GetClientLogger()->info(__VA_ARGS__)
#define LU_APP_WARN(...)		::Lulu::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LU_APP_ERROR(...)		::Lulu::Log::GetClientLogger()->error(__VA_ARGS__)
#define LU_APP_CRITICAL(...)	::Lulu::Log::GetClientLogger()->critical(__VA_ARGS__)