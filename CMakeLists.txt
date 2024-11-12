cmake_minimum_required(VERSION 3.29.0)
project(planning)
set(CMAKE_CXX_STANDARD 17)

# 变量和目录设置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) # 把动态库和exe都指定到bin目录下面；

# CMAKE_LIBRARY_OUTPUT_DIRECTORY   Linux
# CMAKE_ARCHIVE_OUTPUT_DIRECTORY   静态库

# 动态库
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS) # 抓取src cpp文件
add_library(common
    SHARED
    ${SRC_LISTS}) # 生成动态库

target_include_directories(common
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include) # 包含头文件目录

# set(EXECUTABLE_OUTPUT_PATH${PROJECT_SOURCE_DIR}/bin) exe输出目录

# 可执行文件
add_executable(planning_main planning_main.cpp)

target_include_directories(planning_main
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include) # 包括头文件目录

# 链接
target_link_libraries(planning_main
    PUBLIC
    common) # 链接到动态库
