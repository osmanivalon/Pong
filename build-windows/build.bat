cd /d %~dp0

@echo off
color B
echo
echo =============================================================
echo                  Build Preparation
echo =============================================================


cmake -DCMAKE_TOOLCHAIN_FILE=C:\views\vcpkg\scripts\buildsystems\vcpkg.cmake ..

color A
echo 
echo =============================================================
echo                     Generations
echo =============================================================
cmake --build .