#pragma once
#include <windows.h>
#include <gl/Gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

extern void OpenglInit(int argc, char** argv);
struct Vector2D
{
	float fX;
	float fY;
};

extern Vector2D g_vector2D;

void DisplayFunc();//显示函数

void IdleFunc();//闲置时调用的函数

void KeyboardFunc(unsigned char Key, int x, int y);//数字、字母键按键检测

void SpecialFunc(int Key, int x, int y);//F1~F12、控制键检测

void MouseFunc(int button, int state, int x, int y);//鼠标检测

void MotionFunc(int x, int y);//鼠标按着拖动

void PassiveMotionFunc(int x, int y);//鼠标移动
