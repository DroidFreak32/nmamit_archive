#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

float p[41];
float q[41];
float r[41];
float u1=0,u2=1;

float xmin=100,ymin=100,xmax=200,ymax=200;
float x0=50,y0=50,x1=250,y1=250;

void drawRekt(int trans){
    glLineWidth(3);
    glColor3f(1,0.5,0.5);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin+trans,ymin+trans);
        glVertex2f(xmax+trans,ymin+trans);
        glVertex2f(xmax+trans,ymax+trans);
        glVertex2f(xmin+trans,ymax+trans);
    glEnd();
    glFlush();
}

void drawLine(int trans){
    glLineWidth(3);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
        glVertex2f(x0+trans,y0+trans);
        glVertex2f(x1+trans,y1+trans);
    glEnd();
}

float max(float val1,float val2){
   if(val1 > val2)
      return val1;
   else
       return val2;
}

float min(float val1,float val2){
    if(val1 < val2)
      return val1;
   else
       return val2;
}

void barskyClip(){
    float dx,dy;
    float x,y;
    int reject = false;

    dx=x1-x0;
    dy=y1-y0;

    p[1] = -dx;
    p[2] = dx;
    p[3] = -dy;
    p[4] = dy;

    q[1] = x0-xmin;
    q[2] = xmax-x0;
    q[3] = y0-ymin;
    q[4] = ymax-y0;

    for(int i=1;i<=4;i++)
      if(p[i]==0 && q[i]<0)
          reject = true;

    if(reject!=true){
        for(int j=1;j<=4;j++)
            r[j]=q[j]/p[j];
        for(int k=1;k<=4;k++) {
            if(p[k]<0)
                u1 = max(u1,r[k]);
            else
                u2 = min(u2,r[k]);
        }

        if(u1>u2)
           reject = true;

        else if(reject==false){
            x=x0;
            y=y0;
            x0=x+u1*dx;
            y0=y+u1*dy;
            x1=x+u2*dx;
            y1=y+u2*dy;

            drawRekt(200);
            drawLine(200);
       }
    }
}

int init(){
	glClearColor(0,0,0,0.5);
	glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}

void display(){
    drawRekt(0);
    drawLine(0);
    barskyClip();
    glFlush();
}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
	glutInitWindowSize(600,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Liang Barsky");
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
    glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
