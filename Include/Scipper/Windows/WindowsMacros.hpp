// Copyright 2021 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <stdexcept>

#define SCIPPER_WINDOWS_ASSERT(exp, ...)		if(!SUCCEEDED(exp)) throw std::runtime_error(__VA_ARGS__)
