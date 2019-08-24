#  Ubuntu 18.04  
## Installation  
Download package from the following website: https://opencv.org/releases/  
```bash
# mkdir build
# cd build
# cmake ..
# make -j8
# make install
```

## Example (CMake)
CMakeLists.txt
```c++
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
```c++
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

	Mat img(800, 600, CV_8UC3, Scalar(128,0,0));	
	imshow("Image Viewer",img);
	waitKey(0);
	return 0;
}
```


## Basic Operation  
### [*Matrix*]()    
```c++
// Create
Mat I1=(Mat_<double>(1,3) << 2,4,6);
Mat I2=(Mat_<double>(1,3) << 1,2,3);

// Add 
cout<<I1+I2<<endl;

// Substract
cout<<I1-I2<<endl;

// Transpose  
cout<<I1.t()<<endl;

// Invert
// CV_LU - 最佳主元选取的高斯消除法
// CV_SVD - 奇异值分解法 (SVD)
// CV_SVD_SYM - 对正定对称矩阵的 SVD 方法
I1.inv(CV_LU);

// 矩阵底部添加、删除元素
A.push_back(B);    //B添加在A的底部，B可以是常数
A.pop_back(m);    //从A的底部删除m行
```






### [*Create Mat*]()
```c++
// Method1: Init and create at the same time
Mat M(7,7,CV_32FC2,Scalar(1,3));
Mat img(5, 5, CV_8UC3, Scalar(128,0,0));

// Method2: create first, then init
Mat M;
M.create(100,60,CV_8UC(15));
```


### [*Rodrigues (Convert rotation vector to rotation matrix)*]()
```c++
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{	
	Mat rotation_vector = (Mat_<double>(3, 1) << 0, 0 , CV_PI/2);   // rotation vector
	Mat rotation_matrix;                                            // rotaiton matrix
	Rodrigues(rotation_vector, rotation_matrix);                    // calculate 
	
	Mat initial_vector = (Mat_<double>(3, 1) << 5.13506, 4.70901, 0);
	Mat des_vector = rotation_matrix * initial_vector;
	cout << des_vector << endl;
	return 0;
}
```

### [*Access Mat*]()
```c++
Mat dat= (Mat_<double>(3, 1) << 1,2,3);  // the type should be consistent
cout<<dat.ptr<double>(0)[0], dat.ptr<double>(1)[0], dat.ptr<double>(2)[0]<<endl;  
```

