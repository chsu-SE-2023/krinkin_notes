cmake_minimum_required(VERSION 3.16)

project(QtProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES src/Source.cpp
    src/gateway.h
    src/gateway.cpp
    src/net_device.h
    src/net_room.cpp
    src/net_room.h
    src/repeater.h
    src/repeater.cpp
    src/router.h
    src/router.cpp
    src/stats.h
    src/stats.cpp
    src/switch.h
    src/switch.cpp
    src/tests.h
    src/tests.cpp
    src/wl_repeater.h
    src/wl_repeater.cpp
)

add_executable(QtProject ${SOURCES})

include(GNUInstallDirs)
install(TARGETS QtProject
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
