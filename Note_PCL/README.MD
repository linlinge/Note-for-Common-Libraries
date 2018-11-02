# 1. PCL Installation and Configuration
## STEP 1: ubuntu & qt & cmake
```
# sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
# sudo apt-get update
# sudo apt-get install libpcl-all
```
## STEP 2: CMakeLists.txt
```
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(cloud_viewer)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (cloud_viewer main.cpp)
target_link_libraries (cloud_viewer ${PCL_LIBRARIES})
```
## STEP 3: EXAMPLE 1 with PCLVisualizer
```
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
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPLYFile<pcl::PointXYZ>("/home/linlinge/Desktop/1.ply", *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
     viewer->setBackgroundColor (0.33, 0.97, 0.59);
     //设置点云颜色，该处为单一颜色设置
     pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 255, 255, 255);

     //添加需要显示的点云数据
     viewer->addPointCloud<pcl::PointXYZ> (cloud, single_color, "sample cloud");


    //viewer->showCloud(cloud);
    while(!viewer->wasStopped()){
        viewer->spinOnce (100);
        boost::this_thread::sleep (boost::posix_time::microseconds (100000));
    }
  return (0);
}
```

## STEP 3: Example 2 with PointCloud
```
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/cloud_viewer.h>

int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPLYFile<pcl::PointXYZ>("/home/linlinge/Desktop/bunny.ply", *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        system("PAUSE");
        return (-1);
    }
    //pcl::StatisticalOutlierRemoval::applyFileter()
    pcl::visualization::CloudViewer viewer("Viewer");
    viewer.showCloud(cloud);

    while(!viewer.wasStopped());
    return (0);
}
``` 
# 2. User Manual  
## Read  
* Black-white
```
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
if (pcl::io::loadPLYFile<pcl::PointXYZ>("/home/linlinge/Desktop/1.ply", *cloud) == -1) 
{
	PCL_ERROR("Couldn't read file test_pcd.pcd \n");
	return (-1);
}
```
* colorful
```
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
if (pcl::io::loadPLYFile<pcl::PointXYZRGB>("/home/linlinge/Desktop/1.ply", *cloud) == -1)
{
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        return (-1);
}
```
## Display  
* single color
```
// Define Viewer
boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));

// Define Background
viewer->setBackgroundColor (0.33, 0.97, 0.59);

//Set Point Cloud Color
pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 255, 255, 255);

// Add Point Cloud to Viewer
viewer->addPointCloud<pcl::PointXYZ> (cloud, single_color, "sample cloud");

// Show Point Cloud
 while(!viewer->wasStopped()){
        //viewer->spinOnce (100);
        viewer->spin();
        boost::this_thread::sleep (boost::posix_time::microseconds (100000));
 }
```
* multi-color  
```
boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
viewer->setBackgroundColor (0.33, 0.97, 0.59);

//设置点云颜色，该处为单一颜色设置
//pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> rgb(cloud);

pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);

//添加需要显示的点云数据
viewer->addPointCloud<pcl::PointXYZRGB> (cloud, rgb, "sample cloud");

while(!viewer->wasStopped()){
//viewer->spinOnce (100);
viewer->spin();
boost::this_thread::sleep (boost::posix_time::microseconds (100000));
}
```


