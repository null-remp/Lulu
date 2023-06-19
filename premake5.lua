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
IncludeDir["Glad"] = "Lulu/vendor/Glad/include"
IncludeDir["ImGui"] = "Lulu/vendor/imgui"


include "Lulu/vendor/GLFW"
include "Lulu/vendor/Glad"
include "Lulu/vendor/imgui"

project "Lulu"
	location "Lulu"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"LU_PLATFORM_WINDOWS",
			"LU_BUILD_DLL",
			"LU_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "LU_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "LU_RELEASE"
		runtime "Release"
		optimize "On"
	
	filter "configurations:Dist"
		defines "LU_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		systemversion "latest"

		defines 
		{
			"LU_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LU_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "LU_RELEASE"
		runtime "Release"
		optimize "On"
	
	filter "configurations:Dist"
		defines "LU_DIST"
		runtime "Release"
		optimize "On"