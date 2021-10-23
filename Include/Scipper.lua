-- Copyright 2021 Dhiraj Wishal
-- SPDX-License-Identifier: Apache-2.0

---------- Scipper project description ----------

project "Scipper"
	language "C++"
	kind "StaticLib"
	systemversion "latest"
	cppdialect "C++17"
	staticruntime "on"

	flags { "MultiProcessorCompile" }

	targetdir "%{wks.location}/Builds/Binaries/%{cfg.longname}"
	objdir "%{wks.location}/Builds/Intermediate/%{cfg.longname}"

	files {
		"**.txt",
		"**.cpp",
		"**.hpp",
		"**.lua",
		"**.txt",
		"**.md",
	}

	includedirs {
		"%{wks.location}/Include/",
	}

	libdirs {
	}

	links { 
	}

	filter { "toolset:msc", "configurations:Debug" }
	    buildoptions "/MTd"

	filter { "toolset:msc", "configurations:PreRelease" }
	    buildoptions "/MT"

	filter { "toolset:msc", "configurations:Release" }
	    buildoptions "/MT"

	filter ""
