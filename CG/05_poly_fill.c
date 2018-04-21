#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int x1=200, y1=200, x2=100, y2=300, x3=200, y3=400, x4=300, y4=300;
int le[501], re[501];
// void init(){
//     glClearColor(0,0,0,0.5);
//     glClear(GL_COLOR_BUFFER_BIT);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0,500,0,500);
// }

void init(int w,int h) {
	float aspect=(float) w/h;
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if(w>=h)
	    glOrtho(-2.0*aspect,2.0*aspect,-2.0,2.0,2.0,-2.0);
	else
	    glOrtho(-2.0,2.0,-2.0/aspect,2.0/aspect,2.0,-2.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,w,0,h);
	// glMatrixMode(GL_MODELVIEW);
	// glutSwapBuffers();
}

void edgeDetect(int x1, int y1, int x2, int y2){
    int i,y;
    float m,x,temp;
    if((y2-y1)<0){
        temp = x1;
        x1 = x2;
        x2 = temp;
        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    if((y2-y1)!=0)
        m = (x2-x1)/(y2-y1);
    else
        m = x2-x1;
    x=x1;

    for ( i = y1; i < y2; i++){
        if(x<le[i])
            le[i]=x;
        if(x>re[i])
            re[i]=x;
        x=x+m;
    }
}
void scanFill(){

    for (int i = 0; i < 500; i++){
        le[i] = 500;
        re[i] = 0;
    }
    edgeDetect(x1,y1,x2,y2);
    edgeDetect(x2,y2,x3,y3);
    edgeDetect(x3,y3,x4,y4);
    edgeDetect(x4,y4,x1,y1);

    for(int i=0;i<500;i++ ){
        if(le[i] < re[i])
            for(int j = le[i]; j<=re[i]; j++){
                glColor3ub(98,0,255);
                glPointSize(3);
                glBegin(GL_POINTS);
                    glVertex2f(j,i);
                glEnd();
                glFlush();
            }
    }
    return;
}
void display(){
    glColor3ub(211,6,2);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
    glEnd();
    glFlush();
    scanFill();
}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(600,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Poly Fill");
    glutReshapeFunc( init);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
