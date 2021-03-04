project(seminars)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

#add_compile_options(-Wall -Wextra -Werror)

add_compile_options(-fno-elide-constructors)

add_subdirectory(sem1-2)
add_subdirectory(sem3-4)
add_subdirectory(sem5)
add_subdirectory(sem6)
add_subdirectory(sem7)
add_subdirectory(sem8)
add_subdirectory(sem9)
add_subdirectory(sem10)
add_subdirectory(sem11)
add_subdirectory(sem12)
add_subdirectory(sem13)
add_subdirectory(sem14-15)
