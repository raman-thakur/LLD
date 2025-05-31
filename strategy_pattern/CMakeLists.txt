cmake_minimum_required(VERSION 3.10)
project(StrategyPattern)

set(CMAKE_CXX_STANDARD 17)

# Collect all .cpp files
file(GLOB SOURCES
    "*.cpp"
)
  
# Include header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create executable
add_executable(StrategyPattern ${SOURCES})