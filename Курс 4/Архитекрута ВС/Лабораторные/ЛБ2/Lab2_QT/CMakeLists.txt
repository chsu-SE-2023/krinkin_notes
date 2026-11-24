cmake_minimum_required(VERSION 3.16)

project(Lab2_QT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HOMEBREW_PREFIX "/opt/homebrew")
list(APPEND CMAKE_PREFIX_PATH "${HOMEBREW_PREFIX}")
include_directories("${HOMEBREW_PREFIX}/include")
link_directories("${HOMEBREW_PREFIX}/lib")

add_executable(Lab2_QT main.cpp)

find_package(MPI REQUIRED)
target_link_libraries(Lab2_QT PRIVATE MPI::MPI_CXX)

include(GNUInstallDirs)
install(TARGETS Lab2_QT
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
