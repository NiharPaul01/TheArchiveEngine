workspace "TheArchiveEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "TheArchiveEngine/vendor/GLFW/include"
	IncludeDir["Glad"] = "TheArchiveEngine/vendor/Glad/include"
	IncludeDir["ImGui"] = "TheArchiveEngine/vendor/imgui"

	group "Dependencies"
		include "TheArchiveEngine/vendor/GLFW"
		include "TheArchiveEngine/vendor/Glad"
		include "TheArchiveEngine/vendor/imgui"



	

	project "TheArchiveEngine"
		location "TheArchiveEngine"
		kind "SharedLib"
		language "C++"
		staticruntime "Off"

		targetdir("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "aepch.h"
		pchsource "TheArchiveEngine/src/aepch.cpp"

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}


		includedirs{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.ImGui}"
		}

		links{
			"GLFW",
			"Glad",
			"ImGui",
			"opengl32.lib"
		}


		filter "system:windows"
			cppdialect "C++17"
			systemversion "latest"

			buildoptions { "/utf-8" }

			optimize "On"

			defines{
					"AE_PLATFORM_WINDOWS",
					"AE_BUILD_DLL",
					"GLFW_INCLUDE_NONE"
					
			}
			postbuildcommands{
				"{COPY} %{cfg.buildtarget.relpath} \" ../bin/" .. outputdir .. "/Sandbox/"
			}

		filter "configurations:Debug"
			defines "AE_DEBUG"
			staticruntime "Off"
			runtime "Debug"
			symbols "On"
			
		filter "configurations:Release"
			defines "AE_RELEASE"
			staticruntime "Off"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "AE_DIST"
			staticruntime "Off"
			runtime "Release"
			optimize "On"

project "Sandbox"
	location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")
		
		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}


		includedirs{
			
			"TheArchiveEngine/vendor/spdlog/include",
			"TheArchiveEngine/src"
		}

		links {
			"TheArchiveEngine"
		}

		filter "system:windows"
			cppdialect "C++17"
			systemversion "latest"



			buildoptions { "/utf-8" }
			
			
			defines{
					"AE_PLATFORM_WINDOWS"
					
			}
			

		filter "configurations:Debug"
			defines "AE_DEBUG"
			staticruntime "Off"
			runtime "Debug"
			symbols "On"
			
		filter "configurations:Release"
			defines "AE_RELEASE"
			staticruntime "Off"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "AE_DIST"
			staticruntime "Off"
			runtime "Release"
			optimize "On"