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

Note:
```c++
// Install imgaug
# conda install -c https://conda.anaconda.org/conda-forge imgaug
```

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
[*reference website*](https://blog.csdn.net/oMoDao1/article/details/81302365) 
```c++
# git clone https://github.com/cocodataset/cocoapi.git
# python setup.py install
```

### [*Step 5: Download the pre-trained weights*]()  
1. Download Pre-trained Weights [*mask_rcnn_coco.h5*](https://github.com/matterport/Mask_RCNN/releases)
2. Place the file in the Mask_RCNN directory

### [*Step 6: Install Jupyter book in conda*]()
```c++
# conda install jupyter notebook
```

### [*Step 6: Test it*]()
Open up the demo.ipynb and run it