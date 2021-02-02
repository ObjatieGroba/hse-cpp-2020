add_executable(sem7.a a.cpp)

add_executable(sem7.boost boost.cpp)

# set(BOOST_ROOT /usr/local/boost/)


find_package(Boost 1.67 COMPONENTS program_options log)
if(NOT Boost_FOUND)
    message( FATAL_ERROR "Boost 1.67 is required" )
endif()

include_directories(SYSTEM PRIVATE ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

target_link_libraries(sem7.boost ${Boost_LIBRARIES})
