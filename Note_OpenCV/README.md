#  Ubuntu 18.04  
## Installation  
Download package from the following website: https://opencv.org/releases/  
```
# mkdir build
# cd build
# cmake ..
# make -j8
# make install
```

## Test  
CMakeLists.txt
```
# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Define project name
project(opencv_example_project)
find_package(OpenCV REQUIRED)

# Declare the executable target built from your sources
add_executable(opencv_example main.cpp)
# Link your application with OpenCV libraries
target_link_libraries(opencv_example ${OpenCV_LIBS})
```

main.cpp  
```
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	// create image
	/*
		CV_8UC1 8位1通道
		CV_8UC3 8位3通道
		CV_32FC1 32位1通道
		CV_64FC1 64位1通道
	*/

	Mat img(5, 5, CV_8UC3, Scalar(128,0,0));
	imwrite("1.jpg",img);
	return 0;
}
```