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

#define BIT(x) (1 << x)