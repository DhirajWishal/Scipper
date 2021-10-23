// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "Scipper/Windows/WindowsAdapters.hpp"
#include "Scipper/Windows/WindowsMacros.hpp"

namespace Scipper
{
	WindowsAdapters::WindowsAdapters()
	{
		// Create the factory.
		IDXGIFactory1* pFactory = nullptr;
		CreateDXGIFactory1(__uuidof(IDXGIFactory1), reinterpret_cast<void**>(&pFactory));

		// Check if the factory was created.
		if (!pFactory)
			throw std::runtime_error("Failed to create the factory!");

		// Create the available adapters.
		int L = 0;
		while (true)
		{
			CComPtr<IDXGIAdapter1> pAdapter = nullptr;
			pFactory->EnumAdapters1(L, &pAdapter);

			if (!pAdapter)
				break;

			mAdapters.push_back(pAdapter);
			L++;
		}

		//delete pRawPointer;
	}
}