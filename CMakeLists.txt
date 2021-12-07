cmake_minimum_required(VERSION 3.15)
# Main Project
project(Games)

# Create bin dir for exe and dll-s
file(MAKE_DIRECTORY "bin")

# add subdir src
add_subdirectory(src)
