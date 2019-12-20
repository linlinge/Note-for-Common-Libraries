## Embench Python Into C++  (Simple Variable)
*myadd.py*  
```python
def myadd(a,b):
    return a+b
```

*CMakeLists.txt*  
```c++
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(ArmadilloDemo)
# python
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# exe
add_executable(ArmadilloDemo main.cpp)

# python
target_link_libraries(ArmadilloDemo ${PYTHON_LIBRARIES})
```

*main.cpp*
```c++
#include <Python.h>
#include<iostream>
using namespace std;
int main()
{
    Py_Initialize();//使用python之前，要调用Py_Initialize();这个函数进行初始化
    if (!Py_IsInitialized())
    {
        printf("初始化失败！");
        return 0;
    }

    PyRun_SimpleString("import sys");
    //这一步很重要，修改Python路径
    PyRun_SimpleString("sys.path.append('/home/llg/workspace_cmake/T01-for-Armadillo/')");

    PyObject * pModule = NULL;//声明变量
    PyObject * pFunc = NULL;// 声明变量

    pModule = PyImport_ImportModule("myadd");//这里是要调用的文件名hello.py
    if (pModule == NULL){
        cout<<"Module Load Failed!"<< endl;
    }

    pFunc = PyObject_GetAttrString(pModule, "myadd");//这里是要调用的函数名
    if(pFun==NULL){
        cout<<"Function Load Failed!"<<endl;
    }
    // PyObject* args = Py_BuildValue("ii", 28, 103);//给python函数参数赋值
    PyObject* args = Py_BuildValue("ii",1,2);//给python函数参数赋值
    PyObject* pRet = PyObject_CallObject(pFunc, args);//调用函数
    int res = 0;
    PyArg_Parse(pRet, "i", &res);//转换返回类型
    cout << "res:" << res << endl;//输出结果

    Py_Finalize();//调用Py_Finalize，这个根Py_Initialize相对应的。

    return 0;
}
```

## C++ Vector to python numpy
```c++
PyObject* args = PyTuple_New(1);
PyObject* pyListX = PyList_New(2);
PyObject* pyListY = PyList_New(2);
PyList_SetItem(pyListX, 0, PyFloat_FromDouble( 1.1 ));
PyList_SetItem(pyListX, 1, PyFloat_FromDouble( 2.2 ));
PyTuple_SetItem(args, 0, pyListX);
// Call Function
PyObject* pReturnValue = PyObject_CallObject(pFunc, args);
// 检查是否为List对象
if(PyList_Check(pReturnValue )){
    // List对象的大小，这里SizeOfList = 3
    int SizeOfList = PyList_Size(pReturnValue);
    for(int i = 0; i < SizeOfList; i++){
        // 获取List对象中的每一个元素
        PyObject *ListItem = PyList_GetItem(pReturnValue, i);
        int NumOfItems = PyList_Size(ListItem);//List对象子元素的大小
        for(int Index_k = 0; Index_k < NumOfItems; Index_k++){
            // 遍历List对象中子元素中的每个元素
            PyObject *Item = PyList_GetItem(ListItem, Index_k);            
            // 输出元素
            qDebug() << PyFloat_AsDouble(Item) <<"\n "; 
            // 释放空间
            Py_DECREF(Item);
        }
        // 释放空间
        Py_DECREF(ListItem); 
    }
}
```


