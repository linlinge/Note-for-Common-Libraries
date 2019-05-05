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
	glutDisplayFunc(DisplayFunc);//��Ļ��ʾ�Ļص�����
	glutIdleFunc(IdleFunc);//����ʱ�ص���������û����Ϣʱ���ã�
	glutKeyboardFunc(KeyboardFunc);//���֡���ĸ���İ������Ļص�����
	glutSpecialFunc(SpecialFunc);//���ⰴ����⣨F1~F12�����Ƽ���
	glutMouseFunc(MouseFunc);//�����
	glutMotionFunc(MotionFunc);//��갴���϶����
	glutPassiveMotionFunc(PassiveMotionFunc);//����ƶ����


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
		//���õ���ɫ
		glColor3f(pow(color,2), color, color); //���õ���ɫ
		for (float posX = 1.0f; posX >= -1.0f; posX -= 0.001f)
		{
			//���Ƶ�
			glVertex2f(posX, posY);
		}
	}
	glEnd();

	glutSwapBuffers();	//swap buffer

}
//����ʱ���õĺ���
void IdleFunc()
{
	glutPostRedisplay();//���»��ƣ�������DisplayFunc()������
}
//���֡���ĸ���������
void KeyboardFunc(unsigned char Key, int x, int y)
{
	if (Key == 'w' || Key == 'W')
	{
		if (g_vector2D.fY < 1.0f)//�����ж�
		{
			g_vector2D.fY += 0.05f;
			cout << "w" << endl;
		}
			
	}

	if (Key == 's' || Key == 'S')
	{
		if (g_vector2D.fY - 0.4f > -1.0f)//�����ж�
			g_vector2D.fY -= 0.05f;
	}

	if (Key == 'a' || Key == 'A')
	{
		if (g_vector2D.fX > -1.0f)//�����ж�
			g_vector2D.fX -= 0.05f;
	}

	if (Key == 'd' || Key == 'D')
	{
		if (g_vector2D.fX + 0.4f < 1.0f)//�����ж�
			g_vector2D.fX += 0.05f;
	}
}
//F1~F12�����Ƽ����
void SpecialFunc(int Key, int x, int y)
{
	if (Key == GLUT_KEY_UP)
	{
		if (g_vector2D.fY < 1.0f)//�����ж�
			g_vector2D.fY += 0.05f;
	}

	if (Key == GLUT_KEY_DOWN)
	{
		if (g_vector2D.fY - 0.4f > -1.0f)//�����ж�
			g_vector2D.fY -= 0.05f;
	}

	if (Key == GLUT_KEY_LEFT)
	{
		if (g_vector2D.fX > -1.0f)//�����ж�
			g_vector2D.fX -= 0.05f;
	}

	if (Key == GLUT_KEY_RIGHT)
	{
		if (g_vector2D.fX + 0.4f < 1.0f)//�����ж�
			g_vector2D.fX += 0.05f;
	}
}
//�����
void MouseFunc(int button, int state, int x, int y)
{
	//button  ��갴�� 0 -- ���    1 -- �м�   2 -- �Ҽ�
	//state  ���״̬  0 -- ����  1 -- ̧��
	//x,y  �������ص����꣨�Դ��ڵ����Ͻ�Ϊԭ�������ϵ��
	std::cout << "�������꣺x = " << x << " ,y = " << y << std::endl;
	if (button == 0)
	{
		if (state == 0)
		{
			std::cout << "����������" << std::endl;
		}
		if (state == 1)
		{
			std::cout << "������̧��" << std::endl;
		}
	}
	if (button == 1)
	{
		if (state == 0)
		{
			std::cout << "����м�����" << std::endl;
		}
		if (state == 1)
		{
			std::cout << "����м�̧��" << std::endl;
		}
	}
	if (button == 2)
	{
		if (state == 0)
		{
			std::cout << "����Ҽ�����" << std::endl;
		}
		if (state == 1)
		{
			std::cout << "����Ҽ�̧��" << std::endl;
		}
	}
}
//��갴���϶�
void MotionFunc(int x, int y)
{
	//x,y  �������ص����꣨�Դ��ڵ����Ͻ�Ϊԭ�������ϵ��
	std::cout << "��갴���϶������꣺x = " << x << " ,y = " << y << std::endl;
}
//����ƶ�
void PassiveMotionFunc(int x, int y)
{
	//x,y  �������ص����꣨�Դ��ڵ����Ͻ�Ϊԭ�������ϵ��
	std::cout << "����ƶ������꣺x = " << x << " ,y = " << y << std::endl;
}