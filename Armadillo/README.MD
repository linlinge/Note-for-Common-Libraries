## Installation
Reference Website:  
https://solarianprogrammer.com/2017/03/24/getting-started-armadillo-cpp-linear-algebra-windows-mac-linux/

```
# sudo apt update
# sudo apt upgrade
// Install Armadillo prerequisites
# sudo apt install cmake libopenblas-dev liblapack-dev

// Download from this website
// http://arma.sourceforge.net/download.html
# cd Downloads/
# cd arma*
# mkdir build & cd build
# cmake ..
# make
# sudo make install
```

## CMakeLists.txt
```
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})
add_executable(foo foo.cc)
target_link_libraries(foo ${ARMADILLO_LIBRARIES})
```