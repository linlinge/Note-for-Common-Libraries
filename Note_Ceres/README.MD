# <centre> Ceres Tutorial </centre>
## Installation
Download from [GitHub](https://github.com/ceres-solver/ceres-solver)
```c++
// CMake
# sudo apt-get install cmake
// google-glog + gflags
# sudo apt-get install libgoogle-glog-dev
// BLAS & LAPACK
# sudo apt-get install libatlas-base-dev
// Eigen3
# sudo apt-get install libeigen3-dev
// SuiteSparse and CXSparse (optional)
// - If you want to build Ceres as a *static* library (the default)
//   you can use the SuiteSparse package in the main Ubuntu package
//   repository:
# sudo apt-get install libsuitesparse-dev
// - However, if you want to build Ceres as a *shared* library, you must
//   add the following PPA:
# sudo add-apt-repository ppa:bzindovic/suitesparse-bugfix-1319687
# sudo apt-get update
# sudo apt-get install libsuitesparse-dev
```

## Example  
[*main.cpp*]()
```c++
#include<iostream>
#include<ceres/ceres.h>

using namespace std;
using namespace ceres;

//第一部分：构建代价函数，重载（）符号，仿函数的小技巧
struct CostFunctor {
   template <typename T>
   bool operator()(const T* const x, T* residual) const {
     residual[0] = T(10.0) - x[0];
     return true;
   }
};

//主函数
int main(int argc, char** argv) {
	google::InitGoogleLogging(argv[0]);

	// 寻优参数x的初始值，为5
	double initial_x = 5.0;
	double x = initial_x;

	// 第二部分：构建寻优问题
	Problem problem;
	//使用自动求导，将之前的代价函数结构体传入，第一个1是输出维度，即残差的维度，第二个1是输入维度，即待寻优参数x的维度。
	CostFunction* cost_function = new AutoDiffCostFunction<CostFunctor, 1, 1>(new CostFunctor); 
	//向问题中添加误差项，本问题比较简单，添加一个就行。
	problem.AddResidualBlock(cost_function, NULL, &x); 

	//第三部分： 配置并运行求解器
	Solver::Options options;
	options.linear_solver_type = ceres::DENSE_QR; //配置增量方程的解法
	options.minimizer_progress_to_stdout = true;//输出到cout
	Solver::Summary summary;//优化信息
	Solve(options, &problem, &summary);//求解!!!

	std::cout << summary.BriefReport() << "\n";//输出优化的简要信息
	//最终结果
	cout<<endl<<"Result"<<endl;
	cout << "	x : "<< x << "\n";
	return 0;
}
```

[*CMakeLists.txt*]()
```c++
cmake_minimum_required(VERSION 2.8)
 
project(helloworld)
 
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})
 
# helloworld
add_executable(helloworld main.cpp)
target_link_libraries(helloworld ${CERES_LIBRARIES})
```
