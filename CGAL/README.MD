# CGGAL Tutorial 
## Reference  
1.  [How to use CGAL with CMake or your own build system ?](https://github.com/CGAL/cgal/wiki/How-to-use-CGAL-with-CMake-or-your-own-build-system)  


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
### [*CMakeLists.txt (Version 1)*]()
```c++
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(cgal_demo)

find_package(CGAL REQUIRED COMPONENTS Core)
add_executable(cgal_demo main.cpp)
target_link_libraries(cgal_demo CGAL::CGAL CGAL::CGAL_Core)
```

### [*CMakeLists.txt (Version 2)*]()   
```c++
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(cgal_demo)

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
### [*Predefined Kernel*]()
```c++
CGAL::Exact_predicates_exact_constructions_kernel
CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt
CGAL::Exact_predicates_exact_constructions_kernel_with_kth_root
CGAL::Exact_predicates_exact_constructions_kernel_with_root_of
CGAL::Cartesian
```

## Common Usages 
### [ *Read (xyz, normal)* ]()  
```c++
#include <CGAL/Simple_cartesian.h>
#include <CGAL/IO/read_xyz_points.h>
#include <CGAL/IO/write_xyz_points.h>
#include <CGAL/property_map.h>
// Types
typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 Point;
typedef Kernel::Vector_3 Vector;

// Reads xyz_normals
std::vector<PointVectorPair> points;
std::ifstream stream(input_filename);
if (!stream ||
  !CGAL::read_xyz_points(stream,
                 std::back_inserter(points),
                 CGAL::parameters::point_map(CGAL::First_of_pair_property_map<PointVectorPair>()).
                 normal_map(CGAL::Second_of_pair_property_map<PointVectorPair>())))
{
 std::cerr << "Error: cannot read file " << input_filename << std::endl;
 return EXIT_FAILURE;
}

// Write xyz_normal
std::ofstream out(output_filename);
out.precision(17);
if (!out ||
  !CGAL::write_xyz_points(
  out, points,
  CGAL::parameters::point_map(CGAL::First_of_pair_property_map<PointVectorPair>()).
  normal_map(CGAL::Second_of_pair_property_map<PointVectorPair>())))
{
	return EXIT_FAILURE;
}
```

### [*Jet Fitting*]()
```c++
// Jet Fitting 3
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Monge_via_jet_fitting.h>

// cartesion coordinate
CGAL::Simple_cartesian<double>::Point_3 p(1.0,2.0,3.0);


// monge form
CGAL::Monge_via_jet_fitting<CGAL::Simple_cartesian<double>>::Monge_form monge_form;

// jet fitting
CGAL::Monge_via_jet_fitting< CGAL::Simple_cartesian<double>> monge_fit;

monge_form = monge_fit(in_points.begin(), in_points.end(), d_fitting, d_monge);

//result 
cout<<monge_form<<endl;
cout<<monge_fit.condition_number()<<endl;
cout<<monge_fit.pca_basis(i).first<<endl;
```

### [*File Operation*]()  
[**PLY file**]()
```c++
#include <CGAL/IO/read_ply_points.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
CGAL::Exact_predicates_inexact_constructions_kernel::FT
CGAL::Exact_predicates_inexact_constructions_kernel::Point_3
CGAL::Exact_predicates_inexact_constructions_kernel::Vector_3
CGAL::cpp11::array<unsigned char, 4> Color;


typedef CGAL::cpp11::tuple<Point, Vector, Color, int> PNCI;
typedef CGAL::Nth_of_tuple_property_map<0, CGAL::cpp11::tuple<Point, Vector, Color, int>> Point_map;
typedef CGAL::Nth_of_tuple_property_map<1, CGAL::cpp11::tuple<Point, Vector, Color, int>> Normal_map;
typedef CGAL::Nth_of_tuple_property_map<2, CGAL::cpp11::tuple<Point, Vector, Color, int>> Color_map;
typedef CGAL::Nth_of_tuple_property_map<3, CGAL::cpp11::tuple<Point, Vector, Color, int>> Intensity_map;


// define points
std::vector<CGAL::cpp11::tuple<Point, Vector, Color, int>> points;

// read ply
// method 01: read and write ply
CGAL::Point_set_3<CGAL::Exact_predicates_inexact_constructions_kernel::Point_3> ps;
ifstream fin(input_filename);
ofstream fout(output_filename);
CGAL::read_ply_point_set(fin,ps);
CGAL::write_ply_point_set(fout,ps);


// method 02: read ply with properties
std::vector<CGAL::cpp11::tuple<Point, Vector, Color, int>> points;
CGAL::read_ply_points_with_properties(
	in,
	std::back_inserter (points),
	CGAL::make_ply_point_reader(Point_map()),
  	std::make_pair(
			Intensity_map(),
			CGAL::PLY_property<int>("intensity")
			),
  	std::make_tuple(
			Color_map(), 
			CGAL::Construct_array(), 
			CGAL::PLY_property<unsigned char>("red"),
			CGAL::PLY_property<unsigned char>("green"),
			CGAL::PLY_property<unsigned char>("blue")
			CGAL::PLY_property<unsigned char>("alpha")
			),
  	CGAL::make_ply_normal_reader (Normal_map())
  )

CGAL::write_ply_points_with_properties
    (f, points.begin(), points.end(),
     CGAL::make_ply_point_writer (Point_map()),
     std::make_tuple(Color_map(),
                     CGAL::PLY_property<unsigned char>("red"),
                     CGAL::PLY_property<unsigned char>("green"),
                     CGAL::PLY_property<unsigned char>("blue"),
                     CGAL::PLY_property<unsigned char>("alpha")),
     std::make_pair (Intensity_map(), CGAL::PLY_property<int>("intensity")));
```

[**xyz file**]()
```c++
#include <CGAL/property_map.h>
#include <CGAL/IO/read_xyz_points.h>
#include <CGAL/IO/write_xyz_points.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_3 Point;

// read
const char* fname = (argc>1)?argv[1]:"data/oni.xyz";
// Reads a .xyz point set file in points[].
// The Identity_property_map property map can be omitted here as it is the default value.
std::vector<Point> points;
std::ifstream stream(fname);
if (!stream ||
  !CGAL::read_xyz_points(stream, std::back_inserter(points),
						 CGAL::parameters::point_map(CGAL::Identity_property_map<Point>())))
{
std::cerr << "Error: cannot read file " << fname << std::endl;
return EXIT_FAILURE;
}

// write
std::ofstream out("statistics-outlier-removal.xyz");    
if (!out ||!CGAL::write_xyz_points(out, points,CGAL::parameters::point_map(CGAL::Identity_property_map<Point>())))
{
  return EXIT_FAILURE;
}
```



## Relationship
```c++
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
```

