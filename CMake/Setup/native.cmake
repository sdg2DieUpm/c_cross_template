# SETUP FOR NATIVE COMPILATION. NO SPECIAL TOOLCHAIN FILE IS REQUIRED

# File extension
if(win32)
    set(PLATFORM_EXTENSION ".exe")
else()
    set(PLATFORM_EXTENSION "")
endif()
# Platform-specific source files
set(PLATFORM_SOURCES "")
# Platform-specific directories with header files
set(PLATFORM_INCLUDE_DIRS "")
