# Scipper

High performance screen capturing library for C++.

## Getting the library
First things first, clone the repository to a local directory.
```bash
git clone https://github.com/DhirajWishal/Scipper {Source}
```
Note: `{Source}` is the source directory where the library is cloned to.

## How to build
Before we begin, make sure that you have [Python](https://www.python.org/) installed.

After successfully cloning, all the build scripts are present within the `{Source}/Scripts` directory, and the required binaries are present within `{Source}/Tools`.
```bash
python BuildScript.py
```

### Windows
For windows, we use [Visual Studio](https://visualstudio.microsoft.com/downloads/) to build the project. Make sure that you have the C++ workloads along with Game development with C++ modules installed.

After the projects are built, open the `Scipper.sln` file in Visual Studio. From here on you can either build the `Test` project which will in return build the `Scipper` project, or else you can manually select and build it.

### Linux
For linux, we use [make](https://www.gnu.org/software/make/). After building the `Makefile`s you can run the make file under `{Source}`. This will build the `Test` project. Optionally you can specify which project to build.

## How to use
Make sure that you link against the `Scipper` static library (which is built in `{Source}/Builds/Binary/{Config}` and have the include directory set under `{Source}/Include`.

## License
This repository is licensed under MIT.