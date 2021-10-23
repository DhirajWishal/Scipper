// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <memory>

namespace Scipper
{
	class Screen;

	/**
	 * Instance object.
	 * This is a unique object which is used to create screen objects. A single application only needs one of these.
	 */
	class Instance
	{
	public:
		/**
		 * Default constructor.
		 */
		Instance() = default;

		/**
		 * Default virtual destructor.
		 */
		virtual ~Instance() = default;

		/**
		 * Create a new screen object.
		 *
		 * @return The screen pointer.
		 */
		virtual std::unique_ptr<Screen> CreateScreen() = 0;
	};

	namespace Creator
	{
		/**
		 * Create a new instance.
		 * This will create the platform specific instance object.
		 *
		 * @return The instance pointer.
		 */
		std::unique_ptr<Instance> CreateInstance();
	}
}