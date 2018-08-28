## Installation and Configuration  
### Codeblocks  
* 1. Go Codeblocks with settings -> compiler -> Linker settings
* 2. Create a Project in codeblocks
* 3. add the following library  
> /usr/lib/x86_64-linux-gnu/libGL.so  
> /usr/lib/x86_64-linux-gnu/libGLU.so  
> /usr/lib/x86_64-linux-gnu/libglut.so  

### template for windows
\#include <windows.h>  
\#include <gl/Gl.h>  
\#include <gl/glu.h>  
\#include <gl/glut.h>  
void myInit()  
{  
  
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
  
### template for linux  
\#include <windows.h>  
\#include <GL/gl.h>  
\#include <GL/glu.h>  
\#include <GL/glut.h>  
void myInit()  
{  
  
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

