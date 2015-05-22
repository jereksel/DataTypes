set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -O2")

add_executable(StackTest main.c)

target_link_libraries(StackTest LINK_PUBLIC Stack)