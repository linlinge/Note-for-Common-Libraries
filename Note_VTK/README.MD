# Introduction of VTK  
## Installation  
```bash
# sudo apt-get install libvtk5-dev
```

## Example
[*CmakeLists.txt*]()
```c++
cmake_minimum_required(VERSION 2.8)

PROJECT(vkt_test)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(vkt_test MACOSX_BUNDLE main.cpp)

if(VTK_LIBRARIES)
  target_link_libraries(vkt_test ${VTK_LIBRARIES})
else()
  target_link_libraries(vkt_test vtkHybrid)
endif()
```

[*main.cpp*]()
```c++
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
 
int main(int, char *[])
{
  // Create a sphere
  vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->SetCenter(0.0, 0.0, 0.0);
  sphereSource->SetRadius(5.0);
 
  //mapper
  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(sphereSource->GetOutputPort());
 
  //actor
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
  //renderer ,renderWindow, renderWindowInteractor.
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
 
  renderer->AddActor(actor);
  renderer->SetBackground(.3, .6, .3); // Background color green
  renderWindow->Render();
  renderWindowInteractor->Start();
  return EXIT_SUCCESS;
}
```
