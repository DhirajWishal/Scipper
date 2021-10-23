// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "WindowsAdapters.hpp"

namespace Scipper
{
	/**
	 * Windows device object.
	 * This object handles a single DirectX device handle.
	 */
	class WindowsDevice
	{
	public:
		/**
		 * Constructor.
		 * 
		 * @param pAdapter The adapter pointer.
		 */
		WindowsDevice(IDXGIAdapter1* pAdapter);

	private:
		CComPtr<ID3D11Device> device;
		CComPtr<ID3D11DeviceContext> context;
	};
}