cmake_minimum_required(VERSION 3.15)
project(cs201hw1)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs201hw1 main.cpp Student.cpp Student.h Course.cpp Course.h RegistrationSystem.cpp RegistrationSystem.h)