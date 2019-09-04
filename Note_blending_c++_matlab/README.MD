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

