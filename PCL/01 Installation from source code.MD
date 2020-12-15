## Requirements
* ubuntu 18.04
* cuda 10.2
* vtk 8.2
* pcl 1.11.1
* gcc g++ 7.5.0
* boost 1.65.1
[ref1](https://blog.csdn.net/weixin_38907330/article/details/107231113) 

```
#添加阿里源
deb http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
```

## 1. 先安装好 显卡驱动+cuda

https://blog.csdn.net/yfy1127yfy/article/details/87891247

## 2. 安装相关依赖：

主要是boost,vtk两个大件，要注意版本是否适配。

1）其中vtk推荐vtk-8.2: https://vtk.org/download/
```
sudo apt-get install libxt-dev 
# 安装OpenGL Library 
$ sudo apt-get install libgl1-mesa-dev
```
```
tar xzvf VTK-8.2.0.tar.gz
cd VTK-8.2.0
mkdir build
cd build
cmake ..
make -j8
sudo make install
```
2）boost最好安装1.55.0以上的版本，不然会报错:可以去官网上下载源码安装，也可以使用命令行直接搞
```
sudo apt-get install libboost-all-dev
```
3）其他的依赖如flann,eigen
```
  sudo apt-get update  
  sudo apt-get install git build-essential linux-libc-dev  
  sudo apt-get install cmake cmake-gui   
  sudo apt-get install libusb-1.0-0-dev libusb-dev libudev-dev  
  sudo apt-get install mpi-default-dev openmpi-bin openmpi-common    
  sudo apt-get install libflann-dev  
  sudo apt-get install libeigen3-dev  

```

## 3.安装pcl(源码安装)：
```
git clone https://github.com/PointCloudLibrary/pcl
mkdir build
cd build
cmake ..
make -j8
sudo make install
```

1）如果遇到Qt工程中报"c++14"的错，试试添加CONFIG += console c++11 c++14