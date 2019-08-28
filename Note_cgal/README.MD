# CGGAL Tutorial 
## Installation
	// In linux system 
	# sudo apt-get install libcgal-dev
	// Install demo
	# sudo apt-get install libcgal-demo


## Template
### [*main.cpp*]()
```c++
#include <iostream>
#include <string>
#include <CGAL/Point_set_3.h>
#include <CGAL/Point_set_3/IO.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <fstream>
using namespace std;
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
void cgal_read_write_ply(string input_filename,string output_filename)
{
	ifstream fin(input_filename);
	ofstream fout(output_filename);
	
	CGAL::Point_set_3<Kernel::Point_3> ps;
	CGAL::read_ply_point_set(fin,ps);
	CGAL::write_ply_point_set(fout,ps);
}

int main(int argc,char** argv)
{
	if(argc==3)
		cgal_read_write_ply(string(argv[1]),string(argv[2]));
	else
		cout<<"input format error!"<<endl;
	return 0;
}
```
### [*CMakeLists.txt*]()   
```c++
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(read_write_ply_test)

# CGAL and its components
find_package( CGAL REQUIRED)
if ( NOT CGAL_FOUND )
  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()
endif()

# Boost and its components
find_package( Boost REQUIRED )
if ( NOT Boost_FOUND )
  message(STATUS "This project requires the Boost library, and will not be compiled.")
  return()
endif()

set(needed_cxx_features cxx_rvalue_references cxx_variadic_templates)    
create_single_source_cgal_program( "main.cpp" CXX_FEATURES ${needed_cxx_features} )
```
## Structure  
```c++
// Jet Fitting 3
typedef CGAL::Simple_cartesian<double>     Data_Kernel;
typedef Data_Kernel::Point_3     DPoint;
typedef CGAL::Monge_via_jet_fitting<Data_Kernel> My_Monge_via_jet_fitting;
typedef My_Monge_via_jet_fitting::Monge_form     My_Monge_form;
```

## Common Usage  

