cmake_minimum_required(VERSION 3.21)
project(blockchain)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockchain main.cpp Block.hpp Blockchain.hpp sha256.h)
