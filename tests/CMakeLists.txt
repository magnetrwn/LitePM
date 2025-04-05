# file(GLOB_RECURSE TEST_FILES *.c)
# add_executable(litepm_test ${TEST_FILES})

# if(RENDER_BACKEND STREQUAL "SDL2")
#     target_link_libraries(litepm_test ${SDL2_LIBRARIES})
#     target_include_directories(litepm_test PUBLIC ${SDL2_INCLUDE_DIRS})
# endif()