#include <math.h>
#include <GL/glut.h>

#define PI 3.1415926535

void Desenha(void) {
     float angle, raio_x, raio_y;
     int i, circle_points = 1000;
     
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0f, 0, 0);
     glColor3f(0, 1, 0);
     
     // Tamanho do pixel
     glPointSize(1.0);

     // Desenha um círculo preenchido 
     //glBegin(GL_LINE_LOOP);
     glBegin(GL_POLYGON);
               raio_x = 100.0;
               raio_y = 100.0;
               for(i = 0; i < circle_points; i++) {
                 angle = (2*PI*i)/circle_points;
                 glVertex2f(125.0+raio_x*cos(angle),125.0+raio_y*sin(angle));
                 }
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

//void transladar()
//    {
//        object += glm::translate(m_model, glm::vec3(1, 1, 0));
//    }


void Inicializa (void)
{   
    // Cor de fundo
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Chama quando o tamanho da janela é alteradoo
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Correção divisao por zero
                   if(h == 0) h = 1;
                           
                   // Dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

int main(int argc, char ** argv) {
 int sizex, sizey;

 sizex = 500;
 sizey = 500;

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(sizex,sizey);
 glutInitWindowPosition(10,10);
 glutCreateWindow("ccc");
 glutDisplayFunc(Desenha);
 glutReshapeFunc(AlteraTamanhoJanela);
 Inicializa();
 glutMainLoop();

 return 0;
}
