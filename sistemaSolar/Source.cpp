/***********************************PROGRAMA-25*********************************/
// Gera��o autom�tica de coordenadas de textura - Quadric
// Qu�drica: Conjunto de pontos no espa�o tridimensional.

#include <gl/glut.h>
#include <stdio.h>
#include <windows.h>
#include "tga.h"
#include "Planeta.h"



// Prot�tipos de fun��es
void init(void);
void display(void);
void reshape(GLsizei w, GLsizei h);
void load_tga_image(void);


// Vari�veis globais
//tgaInfo *im;
//GLuint texture;
//GLUquadric *mysolid;
//GLfloat spin = 0.05;
float solX=0, solY=0, solZ=0;
Planeta sol, terra, marte;


void init(void)
{
	// Define t�cnica de shading: GL_FLAT, GL_SMOOTH
	glShadeModel(GL_SMOOTH);

	// Activa o teste de profundidade
	glEnable(GL_DEPTH_TEST);
}





void reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.5, 200.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
}




void CreatePlanetas()
{
	sol.CreatePlaneta(2, 0, "images/sun.tga");
	terra.CreatePlaneta(1, 5, "images/earth.tga");
	marte.CreatePlaneta(1, 8, "images/mars.tga");
}

void DrawPlanetas()
{
	
	sol.DrawPlaneta();
	terra.DrawPlaneta();
	marte.DrawPlaneta();
}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(1.0, 1.0, 5.0,0.0, 0.0, 0.0,	0.0, 1.0, 0.0);

	DrawPlanetas();

	glutSwapBuffers();

	glFlush();
}

int main(int argc, char** argv)
{
	int width, height;

	// Inicializa��o do GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

	width = glutGet(GLUT_SCREEN_WIDTH);
	height = glutGet(GLUT_SCREEN_HEIGHT);

	// Cria a janela de visualiza��o
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(width - 14, height - 76);
	glutCreateWindow("Programa-25");
	
	
	// Inicializa��es
	init();
	CreatePlanetas();
	//load_tga_image();
	
	


	// Registar fun��es de callback
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);//display

	// Ciclo infinito do GLUT
	glutMainLoop();

	return 0;
}

/*************************************FIM***************************************/