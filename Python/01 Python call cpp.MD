In [*.cpp]() file:
```c++
// convert char* to string
extern "C" string C2Str(char* s,int len) 
{
  string str;
  for(int i=0;i<2*len;i++)
    str.push_back(s[2*i]);
  return str;
}
```