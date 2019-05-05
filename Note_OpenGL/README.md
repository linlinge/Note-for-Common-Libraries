#  OpenGL Installation and Configuration   
## windows7 & vs2017
### required
glut and glew

### code
```
#include <windows.h>
#include <gl/Gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
void myInit()
{
  glClearColor(0.5, 1, 0.6, 0.1);
  glClear(GL_COLOR_BUFFER_BIT);

  // 把着色模式设置为单调着色
  //glShadeModel(GL_FLAT);
  //glShadeModel(GL_SMOOTH);
  //glFrontFace(GL_CW);
  glOrtho(-1, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
  glRectf(-0.5f, -0.5f, 0.5f, 0.5f);

  /*if (OUTPUT_MODE == 0) {*/
  //	glFlush();//单缓存GLUT_SINGLE时使用
  //}
  //else {
	glutSwapBuffers();//因为使用的是双缓存GLUT_DOUBLE，所以这里必须要交换缓存才会显示
  //}
}

void myDisplay(void)
{
  
}
  
void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("my first attempt");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
```

## ubuntu & Codeblocks  
* 1. Go Codeblocks with settings -> compiler -> Linker settings
* 2. Create a Project in codeblocks
* 3. add the following library
> /usr/lib/x86_64-linux-gnu/libGL.so  
> /usr/lib/x86_64-linux-gnu/libGLU.so  
> /usr/lib/x86_64-linux-gnu/libglut.so  

``` 
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void myInit()
{
  
}
  
void myDisplay(void)
{
  
}
  
int main(int argc,char** argv)
{
        glutInit(&argc,argv);  
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);  
        glutInitWindowSize(640,480);  
        glutInitWindowPosition(100,150);  
        glutCreateWindow("my first attempt");  
        glutDisplayFunc(myDisplay);  
        myInit();  
        glutMainLoop();
        return 0;  
}
```
