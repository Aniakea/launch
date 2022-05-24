# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
#IF(WIN32)
#
#ELSEIF(UNIX)
#ELSEIF(LINUX)
#ENDIF()
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    MESSAGE("Clang")
    set(CMAKE_CXX_STANDARD 14)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    MESSAGE("GNU")
    set(CMAKE_CXX_STANDARD 20)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    MESSAGE("Intel")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    MESSAGE("MSVC")
    set(CMAKE_CXX_STANDARD 14)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project ("launch")

# 包含子项目。
add_subdirectory ("launch")
