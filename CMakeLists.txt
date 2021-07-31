cmake_minimum_required(VERSION 3.20)
project(loxvm C)

set(CMAKE_C_STANDARD 11)

add_executable(loxvm main.c common.h chunk.h chunk.c memory.c memory.h disasm.c disasm.h values.c values.h)
