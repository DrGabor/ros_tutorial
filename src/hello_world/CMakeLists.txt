cmake_minimum_required(VERSION 3.0.2)
project(hello_world)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES hello_world
  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

set(GEOMETRY_SRC
  src/geometry/common.cpp
  src/geometry/line_segment.cpp
)

add_library(${PROJECT_NAME}_geometry
  ${GEOMETRY_SRC}
)

add_executable(hello src/hello_world.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(hello
   ${catkin_LIBRARIES}
   ${PROJECT_NAME}_geometry
)