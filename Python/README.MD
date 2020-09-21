# Package Installation
## matplotlib & ubuntu
```
python -mpip install -U pip
python -mpip install -U matplotlib
apt-get install python3-matplotlib
```


## numpy matrix operation
```python
# dot mutiply
np.dot(A,B)
# Transpose
A.T 
# Inverse
np.linalg.inv(A)
```
## basic operation  
### list all file
```python
def list_all_files(rootdir):
    import os
    _files = []
    # list all files and directory among this file
    list_file = os.listdir(rootdir)
    for i in range(0,len(list_file)):
        # construct path
        path = os.path.join(rootdir,list_file[i])
        # judge the path is a directory or a file
        # if it is a directory, then continue recursive        
        if os.path.isdir(path):
            _files.extend(list_all_files(path))
        if os.path.isfile(path):
             _files.append(path)
    return _files
```