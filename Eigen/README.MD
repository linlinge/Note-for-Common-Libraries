## Installation  
```c++
# sudo apt-get install libeigen3-dev
# sudo cp -r /usr/local/include/eigen3 /usr/include 
```

**CMakeLists.txt**  
```c++ 
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(eigen_example)
include_directories("/usr/include/eigen3")
add_executable (eigen_example main.cpp)
```

## Simple Example  
```c++
# include <iostream>
# include <Eigen/Dense>
using Eigen::MatrixXd;
int main()
{
	/*
	Eigen::MatrixXd - Matrix of double
	Eigen::MatrixXf - Matrix of float
	Eigen::MatrixXi - Matrix of int
	*/
	MatrixXd m(2,2);
	m(0,0) = 3;
	m(1,0) = 2.5;
	m(0,1) = -1;
	m(1,1) = m(1,0) + m(0,1);
	std::cout << m << std::endl;
}
```

## Operation  
```c++
// Header
#include <Eigen/Dense>

// Invert
A.inverse();

// Transpose
A.transpose();

// Merge
M<<m1,m2;

// Transformation
Eigen::Affine3f tf = Eigen::Affine3f::Identity();
tf.translation()<<0,0,0;
tf.rotate(Eigen::AngleAxisf(alpha, Eigen::Vector3f::UnitZ()));
Eigen::Vector3f val(orientations_[i].x,orientations_[i].y,orientations_[i].z);
cout<<(tf*val).transpose()<<endl;
```
