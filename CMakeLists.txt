cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(raylib-turtle)
file(GLOB SOURCES "*.cpp")
set(EXECUTABLE_NAME "main")

# set default path
set(RAYLIB_DIR "C:/MinGW/mingw64/raylib" CACHE PATH "Path to raylib")

# try to find raylib
find_path(RAYLIB_INCLUDE_DIRS raylib.h
    HINTS
        ${RAYLIB_DIR}/include
        ${RAYLIB_DIR}/src
        ${CMAKE_BINARY_DIR}/_deps/raylib-build/raylib/include
        C:/raylib/include
    PATHS
        ${RAYLIB_DIR}
        ${CMAKE_BINARY_DIR}/_deps
    NO_DEFAULT_PATH
)
find_library(RAYLIB_LIBRARY raylib
    HINTS
        ${RAYLIB_DIR}/lib
        ${RAYLIB_DIR}/src
        ${CMAKE_BINARY_DIR}/_deps/raylib-build/raylib/
        C:/raylib/
    PATHS
        ${RAYLIB_DIR}
        ${CMAKE_BINARY_DIR}/_deps
    NO_DEFAULT_PATH
)

if(RAYLIB_INCLUDE_DIRS AND RAYLIB_LIBRARY)
    message(STATUS "Found raylib: ${RAYLIB_INCLUDE_DIRS}")
else()
    message(STATUS "raylib not found, fetching from GitHub")

    # using FetchContent to down load and build raylib
    include(FetchContent)
    FetchContent_Declare(
      raylib
      GIT_REPOSITORY https://github.com/raysan5/raylib.git
      GIT_TAG        5.0
      SOURCE_DIR     ${CMAKE_BINARY_DIR}/_deps/raylib
    )

    FetchContent_GetProperties(raylib)
    if(NOT raylib_POPULATED)
        FetchContent_Populate(raylib)
    endif()

    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

    add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/_deps/raylib-build/libraylib.a
        COMMAND cmake --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/_deps/raylib-build
        DEPENDS ${raylib_SOURCE_DIR}/CMakeLists.txt
        COMMENT "Building raylib"
    )

    add_custom_target(build_raylib ALL
        DEPENDS ${CMAKE_BINARY_DIR}/_deps/raylib-build/libraylib.a
    )

    # set path of include and lib
    set(RAYLIB_INCLUDE_DIRS ${raylib_BINARY_DIR}/raylib/include)
    set(RAYLIB_LIBRARY ${raylib_BINARY_DIR}/raylib/libraylib.a)
endif()

include_directories(${RAYLIB_INCLUDE_DIRS})
add_executable(${EXECUTABLE_NAME} ${SOURCES})
target_link_libraries(${EXECUTABLE_NAME} ${RAYLIB_LIBRARY} opengl32 gdi32 winmm)


add_custom_target(clean-all
    COMMENT "Cleaning all build artifacts..."
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/${EXECUTABLE_NAME}"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/CMakeCache.txt"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/CMakeFiles"
)