cmake_minimum_required(VERSION 2.8.9)
project(socks5)

#set(CMAKE_C_FLAGS "-Wall -O0 -g -DLOG_VERBOSE -std=c99 -D_GNU_SOURCE -Wno-deprecated-declarations -DNO_TERM_COLOR")
set(CMAKE_C_FLAGS "-O2 -DLOG_VERBOSE -std=c99 -D_GNU_SOURCE -Wno-deprecated-declarations -DNO_TERM_COLOR")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SRCS alloc.c server.c socks5.c util.c cli.c)

add_executable(socks5 ${SRCS})

target_link_libraries(socks5 uv)

