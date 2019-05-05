#include "my_opengl.h"
#include <math.h>
#include <GL/glh_glut.h>
using namespace glh;

glut_simple_mouse_interactor object;

Vector2D g_vector2D = { -0.2f,0.2f };


void OpenglInit(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA | GLUT_STENCIL);
	glutInitWindowSize(800, 600);			//set window size
	glutInitWindowPosition(100, 150);		//set window position
	glutCreateWindow("Display");		//window name
	glutDisplayFunc(DisplayFunc);//屏幕显示的回调函数
	glutIdleFunc(IdleFunc);//闲置时回调函数（当没有消息时调用）
	glutKeyboardFunc(KeyboardFunc);//数字、字母键的按键检测的回调函数
	glutSpecialFunc(SpecialFunc);//特殊按键检测（F1~F12，控制键）
	glutMouseFunc(MouseFunc);//鼠标检测
	glutMotionFunc(MotionFunc);//鼠标按着拖动检测
	glutPassiveMotionFunc(PassiveMotionFunc);//鼠标移动检测


	glutMainLoop();
}


void DisplayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//clear color buffer
	glDisable(GL_DEPTH_TEST | GL_LIGHTING);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_SMOOTH);

	glClearColor(0.6f, 0.6f, 0.6f , 0.1);	//can set the background


	float color = 0.0f;
	glBegin(GL_POINTS);
	for (float posY = -1.0f; posY <= 1.0f; posY += 0.001f)
	{
		color += 0.0005f;
		//设置点颜色
		glColor3f(pow(color,2), color, color); //设置点颜色
		for (float posX = 1.0f; posX >= -1.0f; posX -= 0.001f)
		{
			//绘制点
			glVertex2f(posX, posY);
		}
	}
	glEnd();

	glutSwapBuffers();	//swap buffer

}
//闲置时调用的函数
void IdleFunc()
{
	glutPostRedisplay();//重新绘制（即调用DisplayFunc()函数）
}
//数字、字母键按键检测
void KeyboardFunc(unsigned char Key, int x, int y)
{
	if (Key == 'w' || Key == 'W')
	{
		if (g_vector2D.fY < 1.0f)//界限判定
		{
			g_vector2D.fY += 0.05f;
			cout << "w" << endl;
		}
			
	}

	if (Key == 's' || Key == 'S')
	{
		if (g_vector2D.fY - 0.4f > -1.0f)//界限判定
			g_vector2D.fY -= 0.05f;
	}

	if (Key == 'a' || Key == 'A')
	{
		if (g_vector2D.fX > -1.0f)//界限判定
			g_vector2D.fX -= 0.05f;
	}

	if (Key == 'd' || Key == 'D')
	{
		if (g_vector2D.fX + 0.4f < 1.0f)//界限判定
			g_vector2D.fX += 0.05f;
	}
}
//F1~F12、控制键检测
void SpecialFunc(int Key, int x, int y)
{
	if (Key == GLUT_KEY_UP)
	{
		if (g_vector2D.fY < 1.0f)//界限判定
			g_vector2D.fY += 0.05f;
	}

	if (Key == GLUT_KEY_DOWN)
	{
		if (g_vector2D.fY - 0.4f > -1.0f)//界限判定
			g_vector2D.fY -= 0.05f;
	}

	if (Key == GLUT_KEY_LEFT)
	{
		if (g_vector2D.fX > -1.0f)//界限判定
			g_vector2D.fX -= 0.05f;
	}

	if (Key == GLUT_KEY_RIGHT)
	{
		if (g_vector2D.fX + 0.4f < 1.0f)//界限判定
			g_vector2D.fX += 0.05f;
	}
}
//鼠标检测
void MouseFunc(int button, int state, int x, int y)
{
	//button  鼠标按键 0 -- 左键    1 -- 中键   2 -- 右键
	//state  鼠标状态  0 -- 按下  1 -- 抬起
	//x,y  鼠标的像素点坐标（以窗口的左上角为原点的坐标系）
	std::cout << "鼠标的坐标：x = " << x << " ,y = " << y << std::endl;
	if (button == 0)
	{
		if (state == 0)
		{
			std::cout << "鼠标左键按下" << std::endl;
		}
		if (state == 1)
		{
			std::cout << "鼠标左键抬起" << std::endl;
		}
	}
	if (button == 1)
	{
		if (state == 0)
		{
			std::cout << "鼠标中键按下" << std::endl;
		}
		if (state == 1)
		{
			std::cout << "鼠标中键抬起" << std::endl;
		}
	}
	if (button == 2)
	{
		if (state == 0)
		{
			std::cout << "鼠标右键按下" << std::endl;
		}
		if (state == 1)
		{
			std::cout << "鼠标右键抬起" << std::endl;
		}
	}
}
//鼠标按着拖动
void MotionFunc(int x, int y)
{
	//x,y  鼠标的像素点坐标（以窗口的左上角为原点的坐标系）
	std::cout << "鼠标按着拖动的坐标：x = " << x << " ,y = " << y << std::endl;
}
//鼠标移动
void PassiveMotionFunc(int x, int y)
{
	//x,y  鼠标的像素点坐标（以窗口的左上角为原点的坐标系）
	std::cout << "鼠标移动的坐标：x = " << x << " ,y = " << y << std::endl;
}