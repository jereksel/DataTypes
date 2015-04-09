set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O2")

add_executable(ArrayListTest main.c)

target_link_libraries(ArrayListTest LINK_PUBLIC ArrayList)