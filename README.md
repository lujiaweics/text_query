# Text Query System
This text query system is a simple implementation of the program in Chapter 12.3 in *C++ Primer*.  
本文本查询系统是对C++ Primer中12.3章中文本查询系统的实现。

## Directory
```
.
├── CMakeLists.txt
├── include
│   ├── QueryResult.hpp
│   └── TextQuery.hpp
├── README.md
├── res
│   └── article.txt
└── src
    └── main.cpp
```
**src/main.cpp :** 程序入口  
**res/article.txt :** 测试文本  
**include/QueryResult.hpp :** QueryResult类  
**include/TextQuery.hpp :** TextQuery类  
## Usage
- In this version, you can use make to run this project  
在当前版本中，你可以使用make来运行项目代码

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./text_query
```

- or you can use g++ to run this project  
你也可以使用make来运行项目代码
```sh
$ cd src
$ g++ main.cpp ../include/QueryResult.hpp ../include/TextQuery.hpp -o output
$ ./output
```