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
#find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)


add_library(pub SHARED lib/SimplePublisher.cpp)
add_library(sub SHARED lib/SimpleSubscriber.cpp)
ament_target_dependencies(pub rclcpp  std_msgs)
ament_target_dependencies(sub rclcpp  std_msgs)

add_executable(talker src/main.cpp)

target_link_libraries(talker pub sub)
ament_target_dependencies(talker rclcpp  std_msgs )

install(TARGETS
  pub
  sub
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(TARGETS
  talker
  DESTINATION lib/${PROJECT_NAME})

ament_package()
