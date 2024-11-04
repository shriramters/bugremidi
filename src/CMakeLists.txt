cmake_minimum_required(VERSION 3.21)

project(bugremidi LANGUAGES CXX VERSION 0.0.1)

find_package(libremidi 4.5.0 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:libremidi>)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# Install Targets
install(TARGETS ${PROJECT_NAME})
