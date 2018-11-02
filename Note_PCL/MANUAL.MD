# User Manual  
## viewer operation  
1> define viewer
boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));

1> define background  
viewer->setBackgroundColor (0.33, 0.97, 0.59);

2> set point cloud color  
pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 255, 255, 255);

3> add point cloud to viewer  
viewer->addPointCloud<pcl::PointXYZ> (cloud, single_color, "sample cloud");  

4> show point cloud  
 while(!viewer->wasStopped()){
        //viewer->spinOnce (100);
        viewer->spin();
        boost::this_thread::sleep (boost::posix_time::microseconds (100000));
    }  


