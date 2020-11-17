### string
** python → c++ **
```python
# python script
ll = ctypes.cdll.LoadLibrary
lib = ll("./S00_image_generate/build/libshareLib.so")
path="/home/llg"
lib.C2Str(path,len(path)) //convert char* to string
```
```c++
// cpp 
// convert char* to string
extern "C" string C2Str(char* s,int len) 
{
  string str;
  for(int i=0;i<len;i++){
    str.push_back(s[4*i]);
  }
  return str;
}
```

### OpenCV Mat
** python → c++ **
```python
# python
img=cv2.imread(path)
lib.writeMat(img.shape[0],img.shape[1],img.ctypes.data_as(ctypes.c_char_p))
```
```c++
// cpp
extern "C" void writeMat(int rows, int cols, unsigned char* imgData) 
{
  cv::Mat img(rows, cols, CV_8UC3, (void *) imgData);
  cv::imwrite("5.png",img);
}
```