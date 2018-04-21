#include <GL/glut.h>
#include <stdio.h>

int x00,x01,y00,y01;

// void init(){
// 	glClearColor(1,1,1,1);
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	glMatrixMode(GL_PROJECTION);
// 	gluOrtho2D(-500,500,-500,500);
// }

void init(int w,int h) {
	float aspect=(float) w/h;
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	if(w>=h)
	    glOrtho(-2.0*aspect,2.0*aspect,-2.0,2.0,2.0,-2.0);
	else
	    glOrtho(-2.0,2.0,-2.0/aspect,2.0/aspect,2.0,-2.0);
		glMatrixMode(GL_PROJECTION);
	// glMatrixMode(GL_MODELVIEW);
	// glutSwapBuffers();
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
	int d = 2*dy-dx;
	int incrE = dy;
	int incrNE = dy-dx;
	int x = x00;
	int y = y00;
	putPixel(x,y);
	while (x<x01){
		if(d<=0)
			d = d+2*incrE;
		else{
			d = d+2*incrNE;
			y++;
		}
		x++;
		putPixel(x,y);
	}
}
int main(int argc, char ** argv){
	printf("Enter the coordinate x00 y00 x01 y01: ");
	scanf("%d%d%d%d",&x00, &y00, &x01, &y01);
	glutInit(&argc,argv);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("MPLINE");
	glutReshapeFunc(init);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}