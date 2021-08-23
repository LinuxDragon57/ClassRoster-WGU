cmake_minimum_required(VERSION 3.20)
project(ClassRoster)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClassRoster main.cpp degree.h student.cpp student.h roster.cpp roster.h degree.h)
