cmake_minimum_required(VERSION 3.0.0)
project(calculator VERSION 0.1.0)

set ( EXECUTABLE_OUTPUT_PATH bin)

file(GLOB 
    SRC_FILES
    include/*.h
    src/*.C
)
add_executable(calculator ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)