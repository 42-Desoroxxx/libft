cmake_minimum_required(VERSION 3.29)
project(libft C)

file(GLOB SOURCE_FILES "src/*.c")

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
