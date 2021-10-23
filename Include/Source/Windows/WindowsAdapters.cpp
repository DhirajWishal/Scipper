// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "Scipper/Windows/WindowsAdapters.hpp"
#include "Scipper/Windows/WindowsMacros.hpp"

namespace Scipper
{
	WindowsAdapters::WindowsAdapters()
	{
		IDXGIFactory1* pRawPointer = nullptr;
		CreateDXGIFactory1(__uuidof(IDXGIFactory1), reinterpret_cast<void**>(&pRawPointer));

		if (!pRawPointer)
			throw std::runtime_error("Failed to create the factory!");

		int L = 0;
		while (true)
		{
			CComPtr<IDXGIAdapter1> lDxgiAdapter = nullptr;
			pRawPointer->EnumAdapters1(L, &lDxgiAdapter);

			if (!lDxgiAdapter)
				break;

			mAdapters.push_back(lDxgiAdapter);
			L++;
		}

		delete pRawPointer;
	}
}