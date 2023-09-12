# c_template
Template repository for C projects


## File Organization
The application file organization is as follows:

| Main Folder Structure | Description                                                                                                              |
|-----------------------|--------------------------------------------------------------------------------------------------------------------------|
| `.github/`            | Configuration files for GitHub actions on `devel` and `main` branches (to do).                                           |
| `bin/`                | Executables for the application and the tests.                                                                           |
| `build/`        | Compiler's build files.                                                                                                  |
| `project/`            | Project under test. You must paste your code inside this directory.                                                      |
| `test/`               | Test sources and required data for testing.                                                                              |
| `unity/`              | Contains third-party libraries and software to execute C unit tests.                                                     |
| `.gitignore`          | Specifies which files should be ignored by git.                                                                          |
| `.gitmodules`         | Specifies third-party git repositories that are used by this application.                                                |
| `setup.sh`            | Shell script to download third-party repositories and build the software.                                                |
| `build.sh`            | Shell script for building the application. You must execute `setup.sh` before.                                           |
| `CMakeLists.txt`      | CMake lists file. It specifies how to create the `Makefile` of the application using the `cmake` tool.                   |
| `LICENSE`             | License of the application.                                                                                              |
| `README.md`           | Project's ReadMe file.                                                                                                   |
| `run_tests.sh`        | Shell script to run all tests Every time you modify your project, you must run `build.sh` before re-executing the tests. |
