// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "Scipper/Instance.hpp"

#if defined SCP_PLATFORM_WINDOWS
#include "Scipper/Windows/WindowsInstance.hpp"

#endif

namespace Scipper
{
	namespace Creator
	{
		std::unique_ptr<Instance> CreateInstance()
		{
#if defined SCP_PLATFORM_WINDOWS
			return std::make_unique<WindowsInstance>();

#elif defined SCP_PLATFORM_LINUX

#else
#error Unsupported platform!

#endif
		}
	}
}