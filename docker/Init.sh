rm -rf  /etc/apt/sources.list
touch /etc/apt/sources.list
echo "deb http://mirrors.aliyun.com/ubuntu/ trusty main multiverse restricted universe" >> /etc/apt/sources.list
echo "deb http://mirrors.aliyun.com/ubuntu/ trusty-backports main multiverse restricted universe" >> /etc/apt/sources.list
echo "deb http://mirrors.aliyun.com/ubuntu/ trusty-proposed main multiverse restricted universe" >> /etc/apt/sources.list
echo "deb http://mirrors.aliyun.com/ubuntu/ trusty-security main multiverse restricted universe" >> /etc/apt/sources.list
echo "deb http://mirrors.aliyun.com/ubuntu/ trusty-updates main multiverse restricted universe" >> /etc/apt/sources.list
echo "deb-src http://mirrors.aliyun.com/ubuntu/ trusty main multiverse restricted universe" >> /etc/apt/sources.list
echo "deb-src http://mirrors.aliyun.com/ubuntu/ trusty-backports main multiverse restricted universe" >> /etc/apt/sources.list
echo "deb-src http://mirrors.aliyun.com/ubuntu/ trusty-proposed main multiverse restricted universe" >> /etc/apt/sources.list
echo "deb-src http://mirrors.aliyun.com/ubuntu/ trusty-security main multiverse restricted universe" >> /etc/apt/sources.list
echo "deb-src http://mirrors.aliyun.com/ubuntu/ trusty-updates main multiverse restricted universe" >> /etc/apt/sources.list
apt-get update
mkdir ~/.pip
touch  ~/.pip/pip.conf
echo "[global]" >> ~/.pip/pip.conf
echo "timeout = 6000" >> ~/.pip/pip.conf
echo "index-url = https://pypi.tuna.tsinghua.edu.cn/simple" >> ~/.pip/pip.conf
echo "trusted-host = pypi.tuna.tsinghua.edu.cn" >> ~/.pip/pip.conf
