cmake_minimum_required(VERSION 3.10)

# Definitions
set(PROJECT_NAME_STR cmake_boost_demo)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Project title and define versioning
project(${PROJECT_NAME_STR})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include paths
set(DEMO_INCLUDES ${DEMO_INCLUDES} ${PROJECT_SOURCE_DIR}/src)
set(DEMO_INCLUDES ${DEMO_INCLUDES} ${PROJECT_SOURCE_DIR}/shared)

# Gather the header and source files
#file(GLOB_RECURSE INC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
#file(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# Gather all sources except the main entry point
file(GLOB_RECURSE INC_FILES src/*/*.hpp)
file(GLOB_RECURSE SRC_FILES src/*/*.cpp)

# Build object files for reuse (e.g. in test)
#ADD_LIBRARY(demo_objects OBJECT ${INC_FILES} ${SRC_FILES})

# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# Unit tests
add_subdirectory(test)

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})

# Build
#set(SOURCE_FILES src/main.cpp $<TARGET_OBJECTS:demo_objects>)
set(SOURCE_FILES src/main.cpp ${INC_FILES} ${SRC_FILES} src/shared/Tuple.cpp src/shared/Tuple.h src/shared/Point.cpp src/shared/Point.h)
add_executable(cmake_boost_demo ${SOURCE_FILES})
target_link_libraries(cmake_boost_demo ${Boost_LIBRARIES})