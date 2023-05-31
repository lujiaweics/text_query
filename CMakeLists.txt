cmake_minimum_required(VERSION 3.5)

project (text_query C CXX)

add_executable(text_query src/main.cpp include/QueryResult.hpp include/TextQuery.hpp)