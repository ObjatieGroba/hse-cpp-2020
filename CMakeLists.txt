project(seminars)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_compile_options(-Wall -Wextra -Werror)

add_subdirectory(sem1-2)
add_subdirectory(sem3-4)
