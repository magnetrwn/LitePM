cmake_minimum_required(VERSION 3.12)
project(LitePM C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Choose renderer backend (default: SDL2 for prototyping)
set(RENDER_BACKEND "SDL2" CACHE STRING "Rendering backend: SDL2, ILI9341, FBDEV, STUB")

# Set compile definition for use in source code
string(TOUPPER "${RENDER_BACKEND}" RENDER_BACKEND_UPPER)
add_compile_definitions("LITEPM_RENDER_BACKEND_${RENDER_BACKEND_UPPER}")

# If SDL2 is selected, find and configure it
if(RENDER_BACKEND STREQUAL "SDL2")
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    include_directories(${SDL2_INCLUDE_DIRS})
    link_libraries(${SDL2_LIBRARIES})
endif()

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(src)
# add_subdirectory(tests)