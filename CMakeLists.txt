cmake_minimum_required(VERSION 3.16)

project(CyberPong)

FILE(GLOB INCLUDE
        "include/*.cpp")
FILE(GLOB SRC
        "*.cpp"
        "src/*.cpp")
FILE(GLOB BIN_DIR
        "../bin")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

set(CMAKE_MODULE_PATH
        "${CMAKE_SOURCE_DIR}/cmake_modules"
        ${CMAKE_MODULE_PATH})

find_package(SFML REQUIRED system window graphics)

include_directories(${SFML_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SRC} ${INCLUDE})

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENC})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "cpong" RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})