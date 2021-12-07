cmake_minimum_required(VERSION 3.15)

project(Games)


add_subdirectory(src)

# FILE(GLOB SRC
#        "Snake.cpp")

#FILE(GLOB BIN_DIR
#        "bin")

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
# set(CMAKE_MODULE_PATH
#         "${CMAKE_SOURCE_DIR}/cmake_modules"
#         ${CMAKE_MODULE_PATH})

# find_package(SFML REQUIRED system window graphics)


# include_directories(${SFML_INCLUDE_DIR})



# add_executable(${PROJECT_NAME} ${SRC})

# target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENC})

# set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "teris" RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})