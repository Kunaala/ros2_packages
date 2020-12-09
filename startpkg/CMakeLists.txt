cmake_minimum_required(VERSION 3.5)
project(startpkg)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(
  include/startpkg
)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)

find_package(new_interfaces REQUIRED)


add_library(${PROJECT_NAME}_core SHARED
      lib/SimplePublisher.cpp  
      lib/SimpleSubscriber.cpp
      lib/ParameterServer.cpp
)


ament_target_dependencies(${PROJECT_NAME}_core rclcpp std_msgs new_interfaces)

add_executable(talker src/main.cpp)
add_executable(compose lib/simplecompose.cpp)


target_link_libraries(talker ${PROJECT_NAME}_core)
target_link_libraries(compose ${PROJECT_NAME}_core)

ament_target_dependencies(talker rclcpp  std_msgs )

ament_target_dependencies(compose rclcpp  std_msgs rclcpp_components )

install(TARGETS
${PROJECT_NAME}_core 
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(TARGETS
  talker
  compose
  DESTINATION lib/${PROJECT_NAME})

ament_package()
