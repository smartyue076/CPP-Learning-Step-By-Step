### CMake

#### 基础知识

##### 内部构建

源文件在当前目录

```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.13.4) # must be on first line, viewed from cmake --version
project(Hello) # project name, the value of ${PROJECT_NAME}
set(SRC_LIST test.cpp) # define local variable
set(OUT_NAME test)
add_executable(${OUT_NAME} ${SRC_LIST}) # (executable file name, source), here equal to (test test.cpp)
```

```shell
# run in console
cmake -S . -B build # S for source, B for build path
make # auto search for makefile
./Hello # run the executable file
```

##### 外部构建

源文件分布在不同目录

```shell
# tree for dir
● martin ~/Code/test $ tree
.
├── CMakeLists.txt
└── src
    ├── CMakeLists.txt
    └── test.cpp
```

```cmake
# top CMakeLists
cmake_minimum_required(VERSION 3.13.4) # must be on first line, viewed from cmake --version
project(Hello) # project name, the value of ${PROJECT_NAME}
ADD_SUBDIRECTORY(src bin)
```

```cmake
# CMakeLists in src
set(SRC_LIST test.cpp) # define local variable
set(OUT_NAME test)
add_executable(${OUT_NAME} ${SRC_LIST}) # (executable file name, source), here equal to (test test.cpp)
```

```shell
# after make be like
● martin ~/Code/test $ tree -L 3
.
├── CMakeLists.txt
├── build
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   │   ├── 3.24.1
│   │   ├── CMakeDirectoryInformation.cmake
│   │   ├── CMakeError.log
│   │   ├── CMakeOutput.log
│   │   ├── CMakeTmp
│   │   ├── Makefile.cmake
│   │   ├── Makefile2
│   │   ├── TargetDirectories.txt
│   │   ├── cmake.check_cache
│   │   ├── pkgRedirects
│   │   └── progress.marks
│   ├── Makefile
│   ├── bin
│   │   ├── CMakeFiles
│   │   ├── Makefile
│   │   ├── cmake_install.cmake
│   │   └── test (executable file)
│   └── cmake_install.cmake
└── src
    ├── CMakeLists.txt
    └── test.cpp
```

 #### 安装

使得用户可以从其他目录运行可执行文件

```cmake
install(TARGETS ${OUT_NAME} DESTINATION ${INSTALL_PATH}) # if INSTALL_PATH=/usr/local/bin, you can run the exe-file anywhere
```

使用`make install`编译和安装

#### 链接

```cmake
add_library(${LIB_NAME} [STATIC | SHARED | MODULE]  ${SRC_LIST}) # real lib name add lib prefiex
# the mode based on where BUILD_SHARED_LIBS is on, on for share, off for static
```

静态链接：在链接阶段，会将汇编生成的目标文件.o与引用到的库一起链接打包到可执行文件)中，运行时不依赖库（后缀为.a）

动态链接：编译时并不会被连接到目标代码中，而是在程序运行是才被载入。不同的应用程序如果调用相同的库，那么在内存里只需要有一份该共享库的实例，规避了空间浪费问题（后缀为.so/.dll）

```cmake
target_link_directories(${OUT_NAME} ${LIB_BUILD_PATH})
target_link_libraries(${OUT_NAME} <INTERFACE|PUBLIC|PRIVATE> ${OUT_NAME_OF_LIB})
```

以下是一个简单的例子

**自定义的链接库**

```shell
● martin ~/Code/mylib $ tree
.
├── CMakeLists.txt
├── build
├── include
│   └── mytest.h
└── src
    ├── CMakeLists.txt
    └── mytest.cpp
```

```cmake
# top CMakeLists
cmake_minimum_required(VERSION 3.13.4)
project(PRO_LIB)
ADD_SUBDIRECTORY(src bin)
```

```cmake
# CMakeLists in src
set(SRC_LIST mytest.cpp)
set(OUT_NAME mytest)
add_library(${OUT_NAME} ${SRC_LIST})
```

```shell
# tree of mylib
● martin ~/Code/mylib $ tree -L 3
.
├── CMakeLists.txt
├── build
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   │   ├── 3.24.1
│   │   ├── CMakeDirectoryInformation.cmake
│   │   ├── CMakeError.log
│   │   ├── CMakeOutput.log
│   │   ├── CMakeTmp
│   │   ├── Makefile.cmake
│   │   ├── Makefile2
│   │   ├── TargetDirectories.txt
│   │   ├── cmake.check_cache
│   │   ├── pkgRedirects
│   │   └── progress.marks
│   ├── Makefile
│   ├── bin
│   │   ├── CMakeFiles
│   │   ├── Makefile
│   │   ├── cmake_install.cmake
│   │   └── libmytest.a
│   └── cmake_install.cmake
├── include
│   └── mytest.h
└── src
    ├── CMakeLists.txt
    └── mytest.cpp
```

##### 用户main函数

```shell
# tree of test
● martin ~/Code/test $ tree
.
├── CMakeLists.txt
├── build
└── src
    ├── CMakeLists.txt
    └── main.cpp
```

```cmake
# top CMakeLists
cmake_minimum_required(VERSION 3.13.4)
project(PRO_TEST)
ADD_SUBDIRECTORY(src bin)
```

```cmake
# CMakeLists in src
set(SRC_LIST main.cpp)
set(OUT_NAME main)
add_executable(${OUT_NAME} ${SRC_LIST})
target_link_directories(${OUT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/../mylib/build/bin) # the path of lib
target_link_libraries(${OUT_NAME} mytest) # the OUT_NAME of lib
```

```C++
// main.cpp
#include <iostream>
#include "../../mylib/include/mytest.h"

int main()
{
        int i = my::myadd(1,2);
        std::cout << "result: " << i << std::endl;
        return 0;
}
```

```shell
# tree after linked
● martin ~/Code/test $ tree -L 3
.
├── CMakeLists.txt
├── build
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   │   ├── 3.24.1
│   │   ├── CMakeDirectoryInformation.cmake
│   │   ├── CMakeError.log
│   │   ├── CMakeOutput.log
│   │   ├── CMakeTmp
│   │   ├── Makefile.cmake
│   │   ├── Makefile2
│   │   ├── TargetDirectories.txt
│   │   ├── cmake.check_cache
│   │   ├── pkgRedirects
│   │   └── progress.marks
│   ├── Makefile
│   ├── bin
│   │   ├── CMakeFiles
│   │   ├── Makefile
│   │   ├── cmake_install.cmake
│   │   └── main
│   └── cmake_install.cmake
└── src
    ├── CMakeLists.txt
    └── main.cpp
```

