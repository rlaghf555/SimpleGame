/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "object.h"
Renderer *g_Renderer = NULL;
float g_Time = 0;
float px = 0;
float py = 0;

object *myobject;

void RenderScene(void)	//1초에 최소 60번 이상 출력되어야 하는 함수
{
	//지우고, 렌더링하고, 띄우고!
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	
	myobject->getLocation(&px, &py);


	// Renderer Test
	g_Renderer->DrawSolidRect(px, py, 0, 20, 1, 0, 1, 1);

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
}void KeyInput(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		py += 2;
		myobject->setLocation(px, py);

		break;
	case 'a':
		px -= 2;
		myobject->setLocation(px, py);

		break;
	case 's':
		py -= 2;
		myobject->setLocation(px, py);

		break;
	case 'd':
		px += 2;
		myobject->setLocation(px, py);

		break;
	default:
		
		break;
	}
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);


	myobject = new object();
	myobject->setLocation(0, 0);
	myobject->setSize(-10, 10, 10, 10);
	glutMainLoop();

	delete g_Renderer;

    return 0;
}

