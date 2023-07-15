cmake_minimum_required(VERSION 3.5)

project (text_query C CXX)

aux_source_directory(./include INCLUDE_LIST)
aux_source_directory(./src SRC_LIST)

add_executable(text_query ${SRC_LIST} ${INCLUDE_LIST})