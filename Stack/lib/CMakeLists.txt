add_library(Stack Stack.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -O2")

target_include_directories(Stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})