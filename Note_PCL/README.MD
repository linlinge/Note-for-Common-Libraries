# 1. PCL Installation and Configuration
## STEP 1: ubuntu & qt & cmake
```bash
# sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
# sudo apt-get update
// old version ubuntu
# sudo apt-get install libpcl-all
// ubuntu 18.04 
# sudo apt-get install libpcl-dev
```


## Example  
 [*CMakeLists.txt*]()
```c++
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(pcl_demo)
find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable (pcl_demo main.cpp)
target_link_libraries (pcl_demo ${PCL_LIBRARIES})
``` 
[*main.cpp*]()
```bash
#include <iostream>	
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include<thread>	
typedef pcl::PointXYZRGBA PointType;
int main(int argc,char** argv)
{
	pcl::PointCloud<PointType>::Ptr cloud(new pcl::PointCloud<PointType>);
	if (pcl::io::loadPLYFile<PointType>(argv[1], *cloud) == -1) 
	{
		PCL_ERROR("Couldn't read file test_pcd.pcd \n");
		return (-1);
	}
	
	boost::shared_ptr<pcl::visualization::PCLVisualizer> 
		viewer(new pcl::visualization::PCLVisualizer ("3D Viewer"));
	
	// Set background
	// viewer->setBackgroundColor (0.33, 0.97, 0.59); 
	viewer->setBackgroundColor (1.0f, 1.0f, 1.0f);

	//Set multi-color for point cloud
	pcl::visualization::PointCloudColorHandlerRGBField<PointType> multi_color(cloud);  	
	
	//Add the demostration point cloud data
	viewer->addPointCloud<PointType> (cloud, multi_color, "cloud1");

	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "cloud1");

	while(!viewer->wasStopped()){	
		viewer->spin();
		std::this_thread::sleep_for(10ms);
	}
	return 0;
}
```

## Common Usages
### [*Display*]()   
**PCLVisualizer**
```c++
#include <pcl/visualization/pcl_visualizer.h>

// Display
boost::shared_ptr<pcl::visualization::PCLVisualizer> 
	viewer(new pcl::visualization::PCLVisualizer ("3D Viewer"));

// Set background color
viewer->setBackgroundColor (0.33, 0.97, 0.59); 

// Make sure addCoordinateSystem is before setBackgroundColor
viewer->addCoordinateSystem(1.0f); 
   
// 设置点云颜色，该处为单一颜色设置
pcl::visualization::PointCloudColorHandlerCustom<PointType> single_color(cloud, 255, 255, 255);

// Set point size
viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud name");

// Add arrow
viewer->addArrow<pcl::PointXYZ>(pcl::PointXYZ(0,0,0), pcl::PointXYZ(0,0,1), 1.0f, 0, 0, false, "arrow", 0);

// Add Point Sets     
viewer->addPointCloud<PointType> (cloud, single_color, "sample cloud");

// View loop    
while(!viewer->wasStopped()){
    viewer->spinOnce (100);
    boost::this_thread::sleep (boost::posix_time::microseconds (10));
}
```

**CloudViewer**
```c++
#include <pcl/visualization/cloud_viewer.h>

// display
pcl::visualization::CloudViewer viewer("Viewer");
viewer.showCloud(cloud);
while(!viewer.wasStopped());
``` 

### [*Initialize PointCloud Ptr in Class Member*]()
**Method1**
```c++
cloud_in = PointCloudT::Ptr(new PointCloudT)
```

**Method2**
```c++
PclRegister()
  : cloud_in(new PointCloudT),
{}
```


### [*Read and write*]()  
**ply**
```c++
typedef PointTypeRGBA PointType;
pcl::PointCloud<PointType>::Ptr cloud(new pcl::PointCloud<PointType>);
if (pcl::io::loadPLYFile<PointType>("/home/linlinge/Desktop/1.ply", *cloud) == -1) 
{
	PCL_ERROR("Couldn't read file test_pcd.pcd \n");
	return (-1);
}
pcl::io::savePLYFileASCII("1.ply",*cloud);
```


**PCD**
```c++
typedef  PointTypeRGBA PointType;
#include <pcl/io/pcd_io.h> 

// read PCD
pcl::PCDReader reader; 
reader.read<PointType> ("table_scene_lms400.pcd", *cloud);

// write PCD
pcl::PCDWriter writer;
writer.write<PointType> ("table_scene_lms400_inliers.pcd", *cloud_filtered, false);
```


### [*Color*]()
**Multi-color**  
```c++
boost::shared_ptr<pcl::visualization::PCLVisualizer> 
	viewer(new pcl::visualization::PCLVisualizer ("3D Viewer"));

viewer->setBackgroundColor (0.33, 0.97, 0.59);
//set multi-color for point cloud
pcl::visualization::PointCloudColorHandlerRGBField<PointType> multi_color(cloud);  	
//add the demostration point cloud data
viewer->addPointCloud<PointType> (cloud, multi_color, "sample cloud");  			
while(!viewer->wasStopped()){	
	viewer->spin();
	boost::this_thread::sleep (boost::posix_time::microseconds (10));
}
```
**single color**
```c++
// Define Viewer
boost::shared_ptr<pcl::visualization::PCLVisualizer> 
	viewer(new pcl::visualization::PCLVisualizer ("3D Viewer"));

// Define Background 
viewer->setBackgroundColor (0.33, 0.97, 0.59); 
//Set Point Cloud Color
pcl::visualization::PointCloudColorHandlerCustom<PointType> single_color(cloud, 255, 255, 255);
// Add Point Cloud to Viewer 
viewer->addPointCloud<PointType> (cloud, single_color, "sample cloud"); 
// Show Point Cloud
 while(!viewer->wasStopped())
{
    //viewer->spinOnce (100);
    viewer->spin();
    boost::this_thread::sleep (boost::posix_time::microseconds (10));
 }
```

### [*Nearest Neighbour*]()
	
**K-nearest**
```c++
int K=10;
vector<int> pointIdxNKNSearch(K);
vector<float> pointNKNSquaredDistance(K); 	
pcl::search::KdTree<PointType>::Ptr kdtree (new pcl::search::KdTree<PointType>());
kdtree->setInputCloud(cloud);

if ( kdtree->nearestKSearch (cloud->points[0], K, pointIdxNKNSearch, pointNKNSquaredDistance) > 0 ){
	for (size_t i = 0; i < pointIdxNKNSearch.size (); ++i)
	  std::cout << " "  <<   cloud->points[ pointIdxNKNSearch[i] ].x 
				<< " " << cloud->points[ pointIdxNKNSearch[i] ].y 
				<< " " << cloud->points[ pointIdxNKNSearch[i] ].z 
				<< " (squared distance: " << pointNKNSquaredDistance[i] << ")" << std::endl;
}
```

**Radius**
```c++
pcl::search::KdTree<PointType>::Ptr kdtree (new pcl::search::KdTree<PointType>());
vector<int> pointIdxRadiusSearch;
vector<float> pointRadiusSquaredDistance;
kdtree->setInputCloud(cloud);

if ( kdtree->radiusSearch (cloud->points[0], 0.01, pointIdxRadiusSearch, pointRadiusSquaredDistance) > 0 ){
	for (size_t i = 0; i < pointIdxRadiusSearch.size (); ++i)
	  std::cout << " "  <<   cloud->points[ pointIdxRadiusSearch[i] ].x 
				<< " " << cloud->points[ pointIdxRadiusSearch[i] ].y 
				<< " " << cloud->points[ pointIdxRadiusSearch[i] ].z 
				<< " (squared distance: " << pointRadiusSquaredDistance[i] << ")" << std::endl;
}
```

### [*Normal Estimation*]()  
```c++
#include <pcl/features/normal_3d_omp.h>
pcl::NormalEstimationOMP<PointType, pcl::Normal> ne;	
ne.setInputCloud (cloud);
pcl::search::KdTree<PointType>::Ptr tree(new pcl::search::KdTree<PointType> ());
ne.setSearchMethod (tree);
// Output datasets
pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
// Use all neighbors in a sphere of radius 3cm
ne.setRadiusSearch (0.03);
// Compute the features
ne.compute (*cloud_normals);
```