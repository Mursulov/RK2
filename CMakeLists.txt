cmake_minimum_required(VERSION 3.15)
project(bridge_demo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(tests)

# Установка в локальную директорию
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install CACHE PATH "Installation Directory" FORCE)

# Упаковка
set(CPACK_PACKAGE_NAME "bridge_demo")
set(CPACK_PACKAGE_VENDOR "Terragroup Inc.")
set(CPACK_PACKAGE_CONTACT "maks10122003m@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Bridge Pattern Demo Application")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

set(CPACK_GENERATOR "ZIP")

if(UNIX AND NOT APPLE)
    list(APPEND CPACK_GENERATOR DEB RPM)
endif()

if(WIN32)
    find_program(WIX_EXECUTABLE candle)
    if(WIX_EXECUTABLE)
        list(APPEND CPACK_GENERATOR WIX)
    else()
        find_program(NSIS_EXECUTABLE makensis)
        if(NSIS_EXECUTABLE)
            list(APPEND CPACK_GENERATOR NSIS)
        endif()
    endif()
endif()

if(APPLE)
    list(APPEND CPACK_GENERATOR DragNDrop)
endif()

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maks")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27)")
set(CPACK_RPM_PACKAGE_LICENSE "MIT")

include(InstallRequiredSystemLibraries)
include(CPack)
