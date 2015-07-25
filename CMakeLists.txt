cmake_minimum_required(VERSION 2.8)
project(autUofMShutdown)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
	SOURCE_FILES
	src/main.cpp
)

add_executable(autUofMShutdown ${SOURCE_FILES})

target_link_libraries(autUofMShutdown
	"rt"
)