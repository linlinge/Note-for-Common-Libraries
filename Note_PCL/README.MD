# <center>PCL Tutorial</center>  
## Method 1: Install with Command 
''' 
# sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
# sudo apt-get update
# sudo apt-get install libpcl-all
'''

## Method 2: Installation with Source Code
### compile and install pcl source file
'''
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
'''

### configure qt pro
'''
#Eigen
INCLUDEPATH += /usr/include/eigen3

#Vtk
INCLUDEPATH += /usr/include/vtk-5.10

LIBS += /usr/lib/libvtk*.so

#Boost
INCLUDEPATH += /usr/include/boost

LIBS += /usr/lib/x86_64-linux-gnu/libboost_*.so

#PCL Header
INCLUDEPATH += /usr/local/include/pcl-1.8

#PCL Lib
LIBS        += /usr/local/lib/libpcl_*.so \
'''


### example code
'''
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
'''








