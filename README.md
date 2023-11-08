# c_template
Template repository for C projects


## File Organization
The application file organization is as follows:

| Main Folder Structure | Description                                                                                                              |
|-----------------------|--------------------------------------------------------------------------------------------------------------------------|
| `.github/`            | Configuration files for GitHub actions on `devel` and `main` branches (to do).                                           |
| `.vscode/`            | Configuration files for the Visual Studio Code IDE.                                           |
| `bin/`                | Executables for the application and the tests.                                                                           |
| `build/`        | CMake and make build files.                                                                                                  |
| `common/`            | C source and header files of your project. These files must be platform-agnostic.                                                      |
| `port/`            | C source and header files of your project. These files are platform-specific.                                                      |
| `main.c`            | The main routine of your project. It must contain a C `main` function from which your program starts running.                                                      |
| `test/`               | Test sources and required data for testing.                                                                              |
| `CMakeLists.txt`      | CMake lists file. It specifies how to create the `Makefile` of the application using the `cmake` tool.                   |