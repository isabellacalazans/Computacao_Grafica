#include <GL/glut.h>
#include <math.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

float theta;
float rotation_angle = 0;
float speed = 0.02f;

int ct = 0;
int state = 1;

void rgb_color_code(int rgb[])
{
  int i;
  for(i=0;i<3;i++)
  {
    rgb[i]=rand()%256;
  }
}

void desenha()
{
	int rgb[3];
    char hex[6];
	srand(time(0));
	//cor para o fundo
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	switch(state)
	{
	case 1:
	    if(ct <= 255)
		{
			rotation_angle -= speed;
		}
	}

	glutPostRedisplay();
	glFlush();
	
	
	//recebe o angulo, o multiplicador
	glRotatef(rotation_angle,0,0,1);

	for(int i = 0; i < 360; i++)
	{
		glColor3f(rand()%1, rand()%2, rand()%10);
	}

	glBegin(GL_POLYGON);	//ESTRUTURA

	for(int i = 0; i < 360; i++)
	{ 
		theta = i*3.142/180;
		glVertex2f(250+150*cos(theta), 250+150*sin(theta));
		glColor3ub( rand()%255, rand()%255, rand()%255 );
	}
	
glEnd();
glFlush();
glutSwapBuffers();
};

int main(void)
{
	//inicialização
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(450,450);
	glutCreateWindow("Translate");
	
	//Callback
	glutDisplayFunc(desenha);
	
	//qnt tempo a função vai ser chamada dps de iniciar
	//glutTimerFunc(0, timer, 1);
	
	gluOrtho2D(0,500,0,500);
	//cor para o fundo
	glClearColor(1,1,1,1);
	
	//Loop principal
	glutMainLoop();
	
	return 0;
	
}
