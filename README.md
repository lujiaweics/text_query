# Text Query System
This text query system is a simple implementation of the program in Chapter 12.3 in *C++ Primer*.  
本文本查询系统是对C++ Primer中12.3章和15.9章中文本查询系统的实现。

## Directory
```
.
├── CMakeLists.txt
├── README.md
├── include
│   ├── AndQuery.hpp
│   ├── BinaryQuery.hpp
│   ├── NotQuery.hpp
│   ├── OrQuery.hpp
│   ├── Query.hpp
│   ├── QueryResult.hpp
│   ├── Query_base.hpp
│   ├── TextQuery.hpp
│   ├── WordQuery.hpp
│   └── util.hpp
├── res
│   └── article.txt
└── src
    └── main.cpp
```
**src/main.cpp :** 程序入口  
**res/article.txt :** 测试文本  
## Usage
```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./text_query
```