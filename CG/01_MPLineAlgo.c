#include <GL/glut.h>
#include <stdio.h>

int x00,x01,y00,y01;

void init(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500,500,-500,500);
}

void putPixel(int x, int y){
	glColor3ub(0,0,0);
	glPointSize(5);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
	glFlush();
}
void display(){
	int dx = x01 - x00;
	int dy = y01 - y00;
	int d = dy - (dx/2);
	int incrE = dy;
	int incrNE = dy-dx;
	int x = x00;
	int y = y00;
	putPixel(x,y);
	while (x<x01){
		if(d<0)
			d = d+dy;
		else{
			d += (dy - dx);
			y++;
		}
		x++;
		putPixel(x,y);
		printf("\npoint: %d , %d",x,y);
	}
}
void main(int argc, char ** argv){
	printf("Enter the coordinate x00 y00 x01 y01: ");
	scanf(" %d %d %d %d",&x00, &y00, &x01, &y01);
	printf("Coordinates x00 y00 x01 y01: %d %d %d %d",x00, y00, x01, y01);
	glutInit(&argc,argv);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("MPLINE");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}