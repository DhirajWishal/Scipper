// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "Scipper/Windows/WindowsInstance.hpp"
#include "Scipper/Windows/WindowsMacros.hpp"
#include "Scipper/Windows/WindowsDependencies.hpp"
#include "Scipper/Windows/WindowsScreen.hpp"

namespace Scipper
{
	WindowsInstance::WindowsInstance()
	{
		// Query all the adapters.
		WindowsAdapters adapters = {};

		// Iterate and create the device using the best adapter.
		for (const auto pAdapter : adapters.GetAdapters())
		{
			try
			{
				// Create the device.
				pDevice = std::make_unique<WindowsDevice>(pAdapter);

				// Break if the device creation was successful.
				break;
			}
			catch (...) {}
		}

		// If the device wasn't created with the queried adapters, try with the default adapter.
		if (!pDevice)
		{
			try
			{
				// Create the device.
				pDevice = std::make_unique<WindowsDevice>(nullptr);
			}
			catch (...) {}

			// Still if we couldn't create the device, throw the exception.
			if (!pDevice)
				throw std::runtime_error("Failed to create a device using the existing adapters!");
		}
	}
	
	std::unique_ptr<Screen> WindowsInstance::CreateScreen()
	{
		return std::make_unique<WindowsScreen>(this);
	}
}