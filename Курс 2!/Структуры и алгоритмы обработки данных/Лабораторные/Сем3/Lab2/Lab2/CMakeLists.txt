cmake_minimum_required(VERSION 3.16)

project(Lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES Source.cpp
bin_tree.cpp
bin_tree.h)

add_executable(Lab2 ${SOURCES})

include(GNUInstallDirs)
install(TARGETS Lab2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
