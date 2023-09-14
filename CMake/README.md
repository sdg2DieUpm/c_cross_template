# The CMakenomicon

This file explains the CMake build system for the project.
It is intended to be a quick reference for developers who are already familiar with CMake.
If you are new to CMake, you should read the [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html) first.
Only maintainers must read (and understand) this file.
If you are a user of the project and value your sanity, you should not need to read this file.

- `Ld`: Linker files (`.ld`) for different targets.
- `Modules`: CMake modules for finding packages.
- `OpenOCD`: OpenOCD configuration files for different targets.
- `Setup`: CMake modules for setting up the build environment (toolchains, compilation flags, ...).
- `Target`: CMake modules for completing the target builds (linker configuration, post-build commands...).
- `Toolchains`: CMake toolchain files for different targets.
