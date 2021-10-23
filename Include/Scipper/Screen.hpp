// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "Instance.hpp"

namespace Scipper
{
	/**
	 * Screen class.
	 * This object represents one of the following,
	 * 1. Window (this application or another).
	 * 2. Desktop.
	 * 3. Monitor.
	 */
	class Screen
	{
	public:
		/**
		 * Constructor.
		 *
		 * @param pInstance The instance pointer.
		 */
		Screen(Instance* pInstance) {}

		/**
		 * Default virtual destructor.
		 */
		virtual ~Screen() = default;
	};
}