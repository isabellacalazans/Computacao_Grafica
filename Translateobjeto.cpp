# include <GL/glut.h>

float x_position =0;
float y_position =0;

float x_scale =1;
float y_scale =1;

float rotation_angle = 0;

float speed = 1.0f;

void desenha(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glColor3f(0,0,1);
	
	gluOrtho2D(-20,20,-20,20);
	
	glTranslatef(x_position,y_position,0);
	
	glRotatef(rotation_angle,0,0,1);
	
	glScalef(x_scale,y_scale,0);
	
	glBegin(GL_QUADS);	
		glVertex2f(-10,-10);	
		glVertex2f(10,-10);
		glColor3f(1,0,0);
		glVertex2f(10,10);
		glVertex2f(-10,10);
	glEnd();
	
	glutSwapBuffers();
}

void timer(int){
	x_position += 0.1f;
	
	glutPostRedisplay();
	
	glutTimerFunc(1000/60,timer,1);
}

void keyboard(unsigned char key, int x, int y){
	if(key==27)
		exit(0);
	
	if(key== 'd')
		x_position += speed;
		
	if(key== 'a')
		x_position -= speed;
		
	if(key== 'w')
		y_position += speed;
		
	if(key== 's')
		y_position -= speed;
		
	if(key== 'q')
		rotation_angle += speed;
	
	if(key== 'e')
		rotation_angle -= speed;
		
	if(key== 'z')
		x_scale += speed/10;
		
	if(key== 'x')
		x_scale -= speed/10;
		
	if(key== 'c')
		y_scale += speed/10;
		
	if(key== 'v')
		y_scale -= speed/10;
	
	glutPostRedisplay();
}

int main(void){
	//Comandos de inicialização
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(500,500);
	glutCreateWindow("Translate");
	
	//Callbacks
	glutDisplayFunc(desenha);
	//glutTimerFunc(0,timer,1);
	glutKeyboardFunc(keyboard);
	
	glClearColor(1,1,1,1);
	
	//Loop Principal
	glutMainLoop();
	
	return 0;
}
