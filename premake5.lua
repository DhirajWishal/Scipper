-- Copyright 2021 Dhiraj Wishal
-- SPDX-License-Identifier: Apache-2.0

workspace "Scipper"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
	}

	startproject "Scipper"

	DebugDirectory = "%{wks.location}/Workspace"

	-- Libraries
	IncludeDir = {}

	-- Binary includes directories
	IncludeLib = {}

	-- Binaries
	Binary = {}

	filter "configurations:Debug"
		defines { "SCP_DEBUG" }
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines { "SCP_RELEASE", "USE_OPTICK=0" }
		optimize "On"
		runtime "Release"

	filter "system:windows"
		defines { "SCP_PLATFORM_WINDOWS" }

		--IncludeLib["GLFW"] = "%{wks.location}/ThirdParty/glfw/src/Release"
        --IncludeLib["Vulkan"] = "%{wks.location}/ThirdParty/Vulkan/lib"
        --IncludeLib["SPIRV_Cross"] = "%{wks.location}/ThirdParty/SPIRV-Cross/Release"
        --IncludeLib["Assimp"] = "%{wks.location}/ThirdParty/Assimp/lib/Release"
        --IncludeLib["benchmark"] = "%{wks.location}/ThirdParty/benchmark/build/src/Release"
		--
		--Binary["GLFW"] = "glfw3dll"
        --Binary["Vulkan"] = "vulkan-1"
        --Binary["Assimp"] = "assimp-vc142-mt"
        --Binary["benchmark"] = "benchmark"

	filter "system:linux"
		defines { "SCP_PLATFORM_LINUX" }

		--IncludeLib["GLFW"] = "%{wks.location}/ThirdParty/glfw/src"
        --IncludeLib["Assimp"] = "%{wks.location}/ThirdParty/Assimp/lib"
        --IncludeLib["benchmark"] = "%{wks.location}/ThirdParty/benchmark/build/src"
		--
		--Binary["GLFW"] = "libglfw3"
        --Binary["Vulkan"] = "vulkan-1"
        --Binary["Assimp"] = "libassimp"
        --Binary["benchmark"] = "libbenchmark"

	filter ""

	include "Include/Scipper.lua"
	include "Test/Test.lua"
