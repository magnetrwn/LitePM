file(GLOB_RECURSE SRC_FILES *.c)
list(REMOVE_ITEM SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
add_library(litepm_core STATIC ${SRC_FILES})

if(RENDERER STREQUAL "SDL2")
    target_link_libraries(litepm_core ${SDL2_LIBRARIES})
    target_include_directories(litepm_core PUBLIC ${SDL2_INCLUDE_DIRS})
endif()

add_executable(litepm_demo main.c)
target_link_libraries(litepm_demo litepm_core)

if(RENDERER STREQUAL "SDL2")
    target_link_libraries(litepm_demo ${SDL2_LIBRARIES})
    target_include_directories(litepm_demo PUBLIC ${SDL2_INCLUDE_DIRS})
endif()
