cmake_minimum_required(VERSION 2.8)
project(lesson1)





add_executable(lesson1 main.cpp)


install(TARGETS lesson1  RUNTIME DESTINATION bin)
