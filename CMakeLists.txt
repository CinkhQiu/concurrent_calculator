cmake_minimum_required(VERSION 3.20)

project(Concurrent_Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(third_party/thread_pool)
include_directories(third_party/MemoryPool)
include_directories(third_party/spdlog/include)

add_executable(app
    src/main.cpp
    src/Calculator.cpp
    src/Logger.cpp
    src/ThreadPoolWrapper.cpp
)

set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)