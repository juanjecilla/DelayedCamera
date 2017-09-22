cmake_minimum_required(VERSION 3.6)
project(DelayedCamera)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -L /lib64")
#set(LIBS "${LIBS} -lusb-1.0 -l pthread")

find_package(OpenCV REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(DelayedCamera ${SOURCE_FILES})

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("include")
target_link_libraries(DelayedCamera ${OpenCV_LIBS})
#target_link_libraries(DelayedCamera ${LIBS})