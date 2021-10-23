// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "Scipper/Instance.hpp"
#include "Scipper/Screen.hpp"

#include <iostream>

int main()
{
	// Try and run the operations.
	try
	{
		// Create a new instance object.
		auto pInstance = Scipper::Creator::CreateInstance();

		// Create the screen pointer.
		auto pScreen = pInstance->CreateScreen();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}