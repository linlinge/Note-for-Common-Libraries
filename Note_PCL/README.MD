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
## STEP 2: CMakeLists.txt
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

### Examples   
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
typedef PointTypeRGBA PointType;
```

**PCLVisualizer**
```c++
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/visualization/pcl_visualizer.h>
int main(int argc, char** argv)
{
    pcl::PointCloud<PointType>::Ptr cloud(new pcl::PointCloud<PointType>);

    if (pcl::io::loadPLYFile<PointType>("/home/linlinge/Desktop/1.ply", *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }

    // Display
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
    viewer->setBackgroundColor (0.33, 0.97, 0.59);     
    pcl::visualization::PointCloudColorHandlerCustom<PointType> single_color(cloud, 255, 255, 255); //设置点云颜色，该处为单一颜色设置     
    viewer->addPointCloud<PointType> (cloud, single_color, "sample cloud"); 						//添加需要显示的点云数据    
    while(!viewer->wasStopped()){
        viewer->spinOnce (100);
        boost::this_thread::sleep (boost::posix_time::microseconds (10));
    }
    return (0);
}
```

**CloudViewer**
```c++
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/cloud_viewer.h>

int main(int argc, char** argv)
{
    pcl::PointCloud<PointType>::Ptr cloud(new pcl::PointCloud<PointType>);

    if (pcl::io::loadPLYFile<PointType>("/home/linlinge/Desktop/bunny.ply", *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        system("PAUSE");
        return (-1);
    }

    // display
    pcl::visualization::CloudViewer viewer("Viewer");
    viewer.showCloud(cloud);
    while(!viewer.wasStopped());



    return (0);
}
``` 
[*Example 03: Search K-nearest or nearest neighbour*]()
	
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

[*Example 04: Normal Estimation*]()  
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

[*Example 05: Read PLY Format*]() 
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


[*Read PCD Format*]()    
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


[*Display with Single Color*]()
```c++
boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer")); // Define Viewer
viewer->setBackgroundColor (0.33, 0.97, 0.59); // Define Background
pcl::visualization::PointCloudColorHandlerCustom<PointType> single_color(cloud, 255, 255, 255); //Set Point Cloud Color
viewer->addPointCloud<PointType> (cloud, single_color, "sample cloud"); // Add Point Cloud to Viewer

// Show Point Cloud
 while(!viewer->wasStopped())
{
    //viewer->spinOnce (100);
    viewer->spin();
    boost::this_thread::sleep (boost::posix_time::microseconds (100000));
 }
```

[*Display with Multi-color*]()  
```c++
boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
viewer->setBackgroundColor (0.33, 0.97, 0.59);
pcl::visualization::PointCloudColorHandlerRGBField<PointType> multi_color(cloud);  	//set multi-color for point cloud
viewer->addPointCloud<PointType> (cloud, multi_color, "sample cloud");  			//add the demostration point cloud data
while(!viewer->wasStopped()){	
	viewer->spin();
	boost::this_thread::sleep (boost::posix_time::microseconds (10));
}
```
  
[*Show Coordinate*]()  
```c++
pcl::visualization::PCLVisualizer viewer;
viewer.addCoordinateSystem(1.0f); // make sure addCoordinateSystem is before setBackgroundColor
viewer.setBackgroundColor(1.0, 1.0, 1.0);  //set background color
```

[*Set Point Size*]()
```c++
viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud name");
```