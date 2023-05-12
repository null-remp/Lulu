workspace "Lulu"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Iclude dirs relative to root folder (solution dirs)
IncludeDir = {}
IncludeDir["GLFW"] = "Lulu/vendor/GLFW/include"

include "Lulu/vendor/GLFW"

project "Lulu"
	location "Lulu"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lupch.hpp"
	pchsource "Lulu/Src/lupch.cpp"

	files 
	{
		"%{prj.name}/Src/**.hpp",
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/Src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{
		"GLFW",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"LU_PLATFORM_WINDOWS",
			"LU_BUILD_DLL",
			"LU_ENABLE_ASSERTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LU_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "LU_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "LU_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/Src/**.hpp",
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp"
	}

	includedirs
	{
		"Lulu/vendor/spdlog/include",
		"Lulu/Src"
	}

	links
	{
		"Lulu"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"LU_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LU_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "LU_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "LU_DIST"
		optimize "On"