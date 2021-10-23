// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <d3d11.h>
#include <vector>
#include <atlcomcli.h>

namespace Scipper
{
	/**
	 * Windows adapters.
	 * A utility class for querying all the available adapters.
	 */
	class WindowsAdapters
	{
	public:
		/**
		 * Constructor.
		 * This will query all the adapters.
		 */
		WindowsAdapters();

		/**
		 * Get the queried adapters.
		 *
		 * @return The adapter vector.
		 */
		std::vector<CComPtr<IDXGIAdapter1>> GetAdapters() const { return mAdapters; }

	private:
		std::vector<CComPtr<IDXGIAdapter1>> mAdapters = {};
	};
}