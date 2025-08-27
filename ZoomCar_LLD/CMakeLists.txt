cmake_minimum_required(VERSION 3.10)

# Project name
project(ZoomCar_LLD)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    main.cpp
    Vehicle.cpp
    VehicleInventryManager.cpp
)

# Include header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create the executable
add_executable(ZoomCar ${SOURCES})
