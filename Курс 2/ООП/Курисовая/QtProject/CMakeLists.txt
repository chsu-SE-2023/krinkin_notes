cmake_minimum_required(VERSION 3.16)

project(QtProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES src/Source.cpp
    src/devices/gateway.h
    src/devices/gateway.cpp
    src/devices/net_device.h
    src/devices/repeater.h
    src/devices/repeater.cpp
    src/devices/router.h
    src/devices/router.cpp
    src/devices/switch.h
    src/devices/switch.cpp
    src/devices/wl_repeater.h
    src/devices/wl_repeater.cpp
    src/containers/net_room.cpp
    src/containers/net_room.h
    src/containers/stats.h
    src/containers/stats.cpp
)

add_executable(QtProject ${SOURCES})

include(GNUInstallDirs)
install(TARGETS QtProject
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
