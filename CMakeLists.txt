cmake_minimum_required(VERSION 3.21)
project(blockchain)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockchain main.cpp Block.h Blockchain.h sha256.h sha256.cpp Block.cpp Blockchain.cpp)
