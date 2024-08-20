cmake_minimum_required(VERSION 3.16)

project(proton_test C CXX)
set(ProtonCpp_DIR "local_install/lib/cmake/ProtonCpp")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(ProtonCpp REQUIRED)

add_executable(main main.cpp)

# Link the Qpid Proton C++ library
target_link_libraries(main PRIVATE Proton::cpp)