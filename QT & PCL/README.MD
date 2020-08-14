# Configure PCL in QT on windows 10  
## dependencies
* qt-opensource-windows-x86-msvc2015_64-5.8.0.exe  
* PCL-1.8.1-AllInOne-msvc2015-win64.exe  

(1) youtube   
https://www.youtube.com/watch?v=1nzHSkY4K18&t=323s
(2) embench QOpenGL to 
https://forum.qt.io/topic/60353/qopenglwindow-calling-initializegl-after-mainwindow-is-shown
(3) use OpenGL in QT
https://blog.csdn.net/haolun_Cplus/article/details/84935458
 
## VCG Demo1
```c++
#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <vcg/complex/complex.h>
// io
#include <wrap/io_trimesh/import.h>
#include <wrap/io_trimesh/export_ply.h>

class MyVertex; class MyEdge; class MyFace;
struct MyUsedTypes : public vcg::UsedTypes<vcg::Use<MyVertex>   ::AsVertexType,
    vcg::Use<MyEdge>     ::AsEdgeType,
    vcg::Use<MyFace>     ::AsFaceType>{};
class MyVertex : public vcg::Vertex< MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Normal3f, vcg::vertex::BitFlags  >{};
class MyFace : public vcg::Face<   MyUsedTypes, vcg::face::FFAdj, vcg::face::VertexRef, vcg::face::BitFlags > {};
class MyEdge : public vcg::Edge<   MyUsedTypes> {};
class MyMesh : public vcg::tri::TriMesh< std::vector<MyVertex>, std::vector<MyFace>, std::vector<MyEdge>  > {};

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    MyMesh m_obj;  //定义一个网格对象
    int mask;     //定义mask
    vcg::tri::io::ImporterOBJ<MyMesh>::Open(m_obj, "E:/Experiment/1.obj",mask);
    printf("Input mesh  vn:%i fn:%i\n", m_obj.VN(), m_obj.FN());


    return a.exec();
}

```