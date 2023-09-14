# Find OpenOCD CLI executable

find_program(OPENOCD_EXECUTABLE openocd)

find_package(PackageHandleStandardArgs)
find_package_handle_standard_args(OpenOCD DEFAULT_MSG OPENOCD_EXECUTABLE)
