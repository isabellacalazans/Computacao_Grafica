#include <GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(100,400);
		glVertex2f(100,100);
		glVertex2f(400,100);
		glVertex2f(400,400);
	glEnd();
	
	glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutCreateWindow("Aprendendo");
	glutDisplayFunc(display);
	gluOrtho2D(0,500,0,500);
	glClearColor(0,0,0.5,0);
	glutMainLoop();
	return 0;
}
