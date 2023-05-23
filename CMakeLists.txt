cmake_minimum_required(VERSION 3.16)
project(ray_game C)

find_package(raylib)

include_directories(src/headers)

include_directories(assets/audio)

add_executable(${PROJECT_NAME} src/main.c)

# add_custom_command(TARGET ray_game POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy assets/audio/pop.mp3 $<TARGET_FILE_DIR:ray_game> )

target_link_libraries(${PROJECT_NAME} raylib)
