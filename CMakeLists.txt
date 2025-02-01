cmake_minimum_required(VERSION 3.29)
project(libft C)

file(GLOB SOURCE_FILES "src/*.c")

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
