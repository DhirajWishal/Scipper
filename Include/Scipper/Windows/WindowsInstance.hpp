// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "Scipper/Instance.hpp"
#include "WindowsDevice.hpp"

namespace Scipper
{
	/**
	 * Windows instance object.
	 */
	class WindowsInstance final : public Instance
	{
	public:
		/**
		 * Constructor.
		 * This will query the adapters and will try to initialize the device. But it couldn't, it'll try to initialize with the default available adapter.
		 * If that too fails, this will throw a std::runtime_error.
		 */
		WindowsInstance();

		/**
		 * Create a new screen object.
		 *
		 * @return The screen pointer.
		 */
		virtual std::unique_ptr<Screen> CreateScreen() override;

	private:
		std::unique_ptr<WindowsDevice> pDevice = nullptr;
	};
}