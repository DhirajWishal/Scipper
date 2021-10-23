// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "Scipper/Windows/WindowsDevice.hpp"
#include "Scipper/Windows/WindowsMacros.hpp"

namespace Scipper
{
	WindowsDevice::WindowsDevice(IDXGIAdapter1* pAdapter)
	{
		// Check if the adapter is valid.
		if (!pAdapter)
			throw std::invalid_argument("Adapter pointer should not be nullptr!");

		HRESULT hr = S_OK;

		// Driver types supported
		D3D_DRIVER_TYPE DriverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE,
		};
		UINT NumDriverTypes = ARRAYSIZE(DriverTypes);

		// Feature levels supported
		D3D_FEATURE_LEVEL FeatureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0,
			D3D_FEATURE_LEVEL_9_3,
			D3D_FEATURE_LEVEL_9_2,
			D3D_FEATURE_LEVEL_9_1
		};
		UINT NumFeatureLevels = ARRAYSIZE(FeatureLevels);

		D3D_FEATURE_LEVEL FeatureLevel;

		// Create device
		for (UINT DriverTypeIndex = 0; DriverTypeIndex < NumDriverTypes; ++DriverTypeIndex)
		{
			hr = D3D11CreateDevice(pAdapter, DriverTypes[DriverTypeIndex], nullptr, D3D11_CREATE_DEVICE_VIDEO_SUPPORT, FeatureLevels, NumFeatureLevels, D3D11_SDK_VERSION, &device, &FeatureLevel, &context);

			// Return if we successfully created a device.
			if (SUCCEEDED(hr))
				return;
		}

		// Throw an exception if device creation failed.
		throw std::runtime_error("Failed to create device!");
	}
}