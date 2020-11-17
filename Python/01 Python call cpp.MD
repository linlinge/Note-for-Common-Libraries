### python (str) -> c++ (string)
python file
```python
ll = ctypes.cdll.LoadLibrary
lib = ll("./S00_image_generate/build/libshareLib.so")
path="/home/llg"
lib.C2Str(path,len(path)) //convert char* to string
```
In [*.cpp]() file:
```c++
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
