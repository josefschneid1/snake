cmake_minimum_required(VERSION 2.8.9)
project(ProjektName)
add_compile_options(-std=c++17 -Wall)
#Bring the headers into the project
include_directories(include)
 
#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

set(CMAKE_BUILD_TYPE Debug)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(ProjektName ${SOURCES})
target_link_libraries(ProjektName ${CURSES_LIBRARIES})

