cmake_minimum_required(VERSION 3.0)

# 项目名称和语言支持
project(llama
  LANGUAGES CXX CUDA
  VERSION 0.1.0
)

include(cmake/cuda.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置 C++ 和 CUDA 标准（推荐统一为 C++17）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 17)  # 需 CUDA 11.0+ 版本支持
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

# 收集源文件（推荐手动列出，避免遗漏或误包含）
set(DIR_TARGET_SRC_CPU
  source/target/cpu/cpu_alloc.cpp
)
set(DIR_COMMON_SRC
  source/base/buffer.cpp
  source/base/alloc.cpp
  source/tensor/tensor.cpp
  source/models/llama2/llama2.cpp
  source/main/main.cpp
  source/main/main.cu
)

# 构建可执行文件
add_executable(llama
  ${DIR_TARGET_SRC_CPU}
  ${DIR_COMMON_SRC}
)

find_package(GTest REQUIRED)
find_package(glog REQUIRED)
find_package(Armadillo REQUIRED)

target_link_libraries(llama sentencepiece glog::glog gtest gtest_main pthread cudart armadillo )
target_include_directories(llama PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(llama PUBLIC ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
set_target_properties(llama PROPERTIES CUDA_SEPARABLE_COMPILATION ON)