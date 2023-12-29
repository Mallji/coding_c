set -e

cd /cygdrive/d/git/coding/cmake-build-debug
/cygdrive/c/Users/q2585/AppData/Local/JetBrains/CLion2023.2/cygwin_cmake/bin/cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
