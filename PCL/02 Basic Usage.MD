# 1. PCL Installation and Configuration
## STEP 1: ubuntu & qt & cmake
```bash
# sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
# sudo apt-get update
// old version ubuntu
# sudo apt-get install libpcl-all
// install (ubuntu 18.04 )
# sudo apt-get install libpcl-dev
// uninstall (ubuntu 18.04)
# sudo apt-get purge libpcl-dev  
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
// 
cloud_in = PointCloudT::Ptr(new PointCloudT)
// or
cloud_outlier_=pcl::PointCloud<PointType>::Ptr(new pcl::PointCloud<PointType>);
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
pcl::search::KdTree<PointType>::Ptr kdtree (new pcl::search::KdTree<PointType>());
kdtree->setInputCloud(cloud);
for(int i=0;i<cloud->points.size();i++){
	vector<int> idx(K);
	vector<float> dist(K);
	pcl::PointCloud<PointType>::Ptr ctmp=pcl::PointCloud<PointType>::Ptr(new pcl::PointCloud<PointType>);
	kdtree->nearestKSearch (cloud->points[i], K, idx, dist);
	for(int j=0;j<idx.size();j++){
	    ctmp->points.push_back(cloud->points[idx[j]]);
	}      
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

### [*Octree*]()
```c++
// 最小体素的边长
float resolution = 0.001;
pcl::octree::OctreePointCloudSearch<PointType> octree(resolution);
octree.setInputCloud(cloud);

// 从输入点云构建八叉树
octree.addPointsFromInputCloud();

// 求出体素边界
int depth = octree.getTreeDepth();
for (auto it = octree.begin(depth);it != octree.end();++it){
	if (it.isLeafNode()){
		// Get minimum and maximum boundary of each voxel
		Eigen::Vector3f  voxel_min, voxel_max;
		octree.getVoxelBounds(it, voxel_min, voxel_max);
		
		/* 
		cout << "最小值： " << voxel_min.x() << " " << voxel_min.y() << " " << voxel_min.z() <<endl;
		cout << "最大值： " << voxel_max.x() << " " << voxel_max.y() << " " << voxel_max.z() <<endl;
		*/
		
		// Get points indices in each voxel
		auto leaf = it.getLeafContainer();
		std::vector<int> indices; 
		leaf.getPointIndices(indices);
	}
}
```
*Octree Properties*
```c++
// Step01: Define Octree and set resolution
pcl::octree::OctreePointCloudSearch<PointType>::Ptr octree_=
pcl::octree::OctreePointCloudSearch<PointType>::Ptr(new pcl::octree::OctreePointCloudSearch<PointType>(0.01));

// Step02: establis octree
octree_->setInputCloud(cloud_);
octree_->addPointsFromInputCloud(); // create octree from point cloud

// Properties:
// Get Depth
int depth = octree_->getTreeDepth();

// Traversing leaf node
for (auto it = octree_->begin(depth);it != octree_->end();++it){	
	if(it.isLeafNode()){
		
		// Calculate Voxel bounding box
		Eigen::Vector3f  voxel_min, voxel_max;
		octree_->getVoxelBounds(it, voxel_min, voxel_max);

		// Get Bounding Box Centre
		Eigen::Vector3f voxel_centre;
		voxel_centre=(voxel_min+voxel_max)/2.0f;

		// Get all points indices in each voxel
		auto leaf = it.getLeafContainer();
		std::vector<int> indices; 
		leaf.getPointIndices(indices);
	}
}
```

*Calculate Eigenvalue and Eigenvector*
```
Eigen::Vector4f centroid;
Eigen::Matrix3f covariance;
pcl::compute3DCentroid(*cloud, centroid);
pcl::computeCovarianceMatrixNormalized(*cloud, centroid, covariance);	
Eigen::SelfAdjointEigenSolver<Eigen::Matrix3f> eigen_solver(covariance, Eigen::ComputeEigenvectors);
Eigen::Matrix3f eig_vec = eigen_solver.eigenvectors();	
Eigen::Vector3f eig_val = eigen_solver.eigenvalues();

eig_vec.col(2) = eig_vec.col(0).cross(eig_vec.col(1));
eig_vec.col(0) = eig_vec.col(1).cross(eig_vec.col(2));
eig_vec.col(1) = eig_vec.col(2).cross(eig_vec.col(0));
cout<<eig_val<<endl;
```

### Random Color  
```c++
for(int i=0;i<clusters.size();i++){
	  int rtmp=rand()%256;
	  int gtmp=rand()%256;
	  int btmp=rand()%256;
	  for(int j=0;j<clusters[i].indices.size();j++){
		  int itmp=clusters[i].indices[j];
		  cloud_rgb->points[itmp].r=rtmp;
		  cloud_rgb->points[itmp].g=gtmp;
		  cloud_rgb->points[itmp].b=btmp;
		  cloud_rgb->points[itmp].x=cloud->points[itmp].x;
		  cloud_rgb->points[itmp].y=cloud->points[itmp].y;
		  cloud_rgb->points[itmp].z=cloud->points[itmp].z;
	  }
  }
```
