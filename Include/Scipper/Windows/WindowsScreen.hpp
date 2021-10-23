// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "Scipper/Screen.hpp"

namespace Scipper
{
	/**
	 * Windows screen object.
	 */
	class WindowsScreen final : public Screen
	{
	public:
		/**
		 * Constructor.
		 * 
		 * @param pInstance The instance pointer.
		 */
		WindowsScreen(Instance* pInstance);
	};
}