cmake_minimum_required(VERSION 3.27)
project(untitled1 C)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)

# Add the executable and list all source and header files
add_executable(untitled1
    main.c
    loc.c
    loc.h
    moves.c
    moves.h
    map.c
    map.h
    queue.c
    queue.h
    stack.c
    stack.h
    prob_mov.c
    prob_mov.h
    n_ary_tree.c
    n_ary_tree.h
)
