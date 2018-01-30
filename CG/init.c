#include <GL/glut.h>
int main(int argc,char *argv[])
{
glutInit(&argc,argv);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("Color");
Init();
display();
glutMainLoop();
return 0;
}
void Init()
{
glClearColor(1.0,0.0,0.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
}
void display()
{
glPointSize(7);
glColor3f(0.0,1.0,0.0);
glBegin(GL_POINTS);
glVertex2f(0,0);
glEnd();
glFlush();
}
