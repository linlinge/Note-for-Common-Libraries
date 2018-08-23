cmake_minimum_required(VERSION 2.8)
project(lesson1)

#set(SDL2_DIR /usr/share/cmake-2.8/Modules)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(lesson1 main.cpp)
target_link_libraries(lesson1 ${SDL2_LIBRARY})  

install(TARGETS lesson1  RUNTIME DESTINATION bin)
