# Tutorial for Mask RCNN  
## Installation  
### [*Step 1: Create a conda virtual environment*]()
```c++
# conda create -n MaskRCNN python=3.6 pip
```

### [*Step 2: Install the dependencies*]()  
1. Download [*requirements.txt*](https://github.com/markjay4k/Mask-RCNN-series/blob/master/requirements.txt)
2. Install 
```c++
# conda activate MaskRCNN
# pip install -r requirements.txt
```
Note:
* numpy
* scipy
* cython
* h5py
* Pillow
* scikit-image
* tensorflow-gpu==1.5
* keras
* jupyter

### [*Step 3: Clone the Mask_RCNN repo*]()
```c++
# git clone https://github.com/matterport/Mask_RCNN.git
```

### [*Step 4: Install pycocotools*]()


1.  Download [*Visual C++ 2015 Build Tools*](https://go.microsoft.com/fwlink/?LinkId=691126)
2. Clone Repo
```c++
# git clone https://github.com/philferriere/cocoapi.git
```
3. Install pycocotools
```c++
pip install git+https://github.com/philferriere/cocoapi.git#subdirectory=PythonAPI
```

### [*Step 5: Download the pre-trained weights*]()  
1. Download [*Pre-trained Weights*](https://github.com/matterport/Mask_RCNN/releases)
2. Download mask_rcnn_coco.h5
3. Place the file in the Mask_RCNN directory

### [*Step 6: Test it*]()
Open up the demo.ipynb and run it