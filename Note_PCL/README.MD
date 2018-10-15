# <center>PCL Installation and Configuration</center>
## Environment 1: ubuntu & kdevelop & cmake
```
# sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
# sudo apt-get update
# sudo apt-get install libpcl-all
```

## Environment 2: ubuntu & QT
### STEP1: Compile and Install PCL Source File
```
# apt-get install cmake g++   libboost-all-dev libeigen3-dev   
# apt-get install libflann-dev python libusb-1.0-0-dev libudev-dev  
# apt-get install freeglut3-dev doxygen graphviz libpng12-dev libgtest-dev  
# apt-get install libxmu-dev libxi-dev libpcap-dev libqhull-dev libvtk5-qt4-dev  
# apt-get install python-vtk libvtk-java  
# git clone https://github.com/PointCloudLibrary/pcl.git
# cd pcl
# mkdir build
# cmake-gui ./
// make sure that the following module is exist
-- common
-- kdtree
-- octree
-- search
-- sample_consensus
-- filters
-- tracking
-- geometry
-- io
-- 2d
-- features
-- visualization
-- ml
-- segmentation
-- people
-- keypoints
-- outofcore
-- stereo
-- surface
-- registration
-- recognition
-- tools

# make install
```

### STEP2: Configure QT .pro File
```
#Eigen
INCLUDEPATH += /usr/include/eigen3

#Vtk
INCLUDEPATH += /usr/include/vtk-5.8

LIBS += /usr/lib/libvtk*.so

#Boost
INCLUDEPATH += /usr/include/boost

LIBS += /usr/lib/x86_64-linux-gnu/libboost_*.so

#PCL Header
INCLUDEPATH += /usr/local/include/pcl-1.8

#PCL Lib
LIBS        += /usr/local/lib/libpcl_*.so \
```

### STEP3: Example
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








