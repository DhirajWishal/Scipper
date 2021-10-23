# Copyright 2021 Dhiraj Wishal
# SPDX-License-Identifier: Apache-2.0

import os

# Build the solution and projects.
os.system("cd .. && call \"Tools/Windows/premake5\" vs2019")