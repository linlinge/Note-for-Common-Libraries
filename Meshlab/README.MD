## Installation  
```c++
// step 01: meshlab
download meshlab-Meshlab-2020.06 from github

// step 02: vcglib
# git clone https://github.com/cnr-isti-vclab/vcglib.git

// step 03
# cd vcglib
// change branch to devel
# git checkout devel
# cp -rf vcg /path/to/meshlab/vcglib
# cp -rf wrap /path/to/meshlab/vcglib
# cp -rf eigenlib /path/to/meshlab/vcglib
```