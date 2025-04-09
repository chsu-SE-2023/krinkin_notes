cmake_minimum_required(VERSION 3.16)

project(QtProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES Source.cpp)

add_executable(QtProject ${SOURCES})

include(GNUInstallDirs)
install(TARGETS QtProject
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
