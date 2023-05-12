#pragma once

#ifdef LU_PLATFORM_WINDOWS
	#ifdef LU_BUILD_DLL
		#define LULU_API __declspec(dllexport)
	#else
		#define LULU_API __declspec(dllimport)
	#endif // LU_BUILD_DLL
#else
	#error Lulu only for OS Windows.
#endif // LU_PLATFORM_WINDOWS

#ifdef LU_ENABLE_ASSERTS
	#define LU_APP_ASSERT(x, ...) { if(!(x)) { LU_APP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LU_CORE_ASSERT(x, ...) { if(!(x)) { LU_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LU_APP_ASSERT(x, ...)
	#define LU_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)