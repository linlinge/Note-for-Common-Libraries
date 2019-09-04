# Blending Programming of C++ and Matlab
## *Call Matlab in C++ on Ubuntu 18.04*  
### [*Step 1: Matlab Installation on Ubuntu 18.04*]()
### [*Step 2: Setting Matlab Compiler*]()
```c++
// open matlab terminal
# /usr/local/MATLAB/R2016b/bin/matlab -nodisplay

// set compiler
>> mex -setup
>> mex -setup C++
>> mbuild -setup
>> mex -setup C++ -client MBUILD
>> exit
```

### [*Step 3: Edit libmyfun.m*]()
```Matlab
function rst=add(a,b)
rst=a+b;
```

### [*Step 4: Compile libmyfun.m*]()
```Matlab
>> mcc -W cpplib:libmyfun -T link:lib libmyfun.m
```

### [*Step 5: C++ Call*]()
[*main.cpp*]()
```c++
#include "mclmcrrt.h"  
#include "mclmcr.h"  
#include "mclcppclass.h"  
#include "matrix.h"
#include <iostream>
#include "libadd.h"
using namespace std;
int main()
{
	 if( !libaddInitialize())    
    {    
        printf("Could not initialize !");    
        return -1;      
    }
	mwArray a(1,1,mxDOUBLE_CLASS);
	mwArray b(1,1,mxDOUBLE_CLASS);
	mwArray c(1,1,mxDOUBLE_CLASS);
	a(1,1)=1;
	b(1,1)=2;
	libadd(1,c,a,b);
	cout<<c(1,1)<<endl;
	return 0;
}

```

[*CMakeLists.txt*]()
```c++
cmake_minimum_required(VERSION 3.0)
 
set(PROJECT_NAME myPrj)
 
project(${PROJECT_NAME})
 
# List COMMAND
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++0x")
 
# matlab
set(MATLAB_ROOT /usr/local/MATLAB/R2016b/)
include_directories(${MATLAB_ROOT}extern/include/)
LINK_DIRECTORIES(${MATLAB_ROOT}runtime/glnxa64/)
 
# libMypr
set(MYPR /home/llg/workspace/test/)
# 前提是已将.h文件和.so文件分别放在include和src中。
include_directories(${MYPR}include/)
LINK_DIRECTORIES(${MYPR}src/)

set(SRCS main.cpp)
add_executable(${PROJECT_NAME} SRCS)
target_link_libraries(${PROJECT_NAME} mwmclmcrrt)
target_link_libraries(${PROJECT_NAME} add)
```