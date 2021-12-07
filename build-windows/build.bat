cd /d %~dp0
cmake -DCMAKE_TOOLCHAIN_FILE=C:\views\vcpkg\scripts\buildsystems\vcpkg.cmake ..
cmake --build .