workspace "TheArchiveEngine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "TheArchiveEngine"
		location "TheArchiveEngine"
		kind "SharedLib"
		language "C++"

		targetdir("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}


		includedirs{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include"
		}


		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			buildoptions { "/utf-8" }

			defines{
					"AE_PLATFORM_WINDOWS",
					"AE_BUILD_DLL",
					
			}
			postbuildcommands{
				"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/"
			}

		filter "configurations:Debug"
			defines "AE_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "AE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "AE_DIST"
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
			staticruntime "On"
			systemversion "latest"



			buildoptions { "/utf-8" }
			
			
			defines{
					"AE_PLATFORM_WINDOWS"
					
			}
			

		filter "configurations:Debug"
			defines "AE_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "AE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "AE_DIST"
			optimize "On"