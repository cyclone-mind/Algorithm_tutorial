cmake_minimum_required(VERSION 3.31)
project(Algorithm_tutorial)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Code_Caprice)
include_directories("hello 算法")

# 自动查找所有 .cpp 文件
file(GLOB_RECURSE SOURCES "Code_Caprice/**/*.cpp")

# 为每个 .cpp 文件生成一个可执行文件
foreach(SOURCE_FILE ${SOURCES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()
