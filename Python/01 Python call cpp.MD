### string
**python → c++**
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

### cv::Mat
**python → c++**
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
**c++ → python**
```python
# python
h=ctypes.c_int(0)
w=ctypes.c_int(0)
lib.Example_Mat_out.restype = ctypes.POINTER(ctypes.c_uint8)     
ptr = lib.Example_Mat_out(ctypes.byref(h),ctypes.byref(w))
img = np.array(np.fromiter(ptr, dtype=np.uint8, count=h.value*w.value*3))
img = img.reshape(h.value,w.value,3)
```
```c++
// c++
extern "C" uchar*  Example_Mat_out(int* rows, int* cols)
{
  cv::Mat img=imread("/home/llg/workspace_cmake/SegOR/1.png");
  *rows=img.rows;
  *cols=img.cols;
  uchar* buffer = (uchar*)malloc(sizeof(uchar)*img.rows*img.cols*3);
  memcpy(buffer, img.data, img.rows*img.cols*3);
  return buffer;
}
```