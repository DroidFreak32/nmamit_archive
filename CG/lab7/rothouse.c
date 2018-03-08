#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <cmath.h>

float initObj[9][3] = {
    {200,200,1},
    {300,200,1},
    {300,300,1},
    {200,300,1},
    {250,350,1},
    {225,200,1},
    {275,200,1},
    {275,250,1},
    {225,250,1},
};
float resObj[9][3],rotMatrix[3][3],theta;

int p,q,r;
void init(){
    glClearColor(0,0,0,0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

void drawInitialObj(){
    /*
    Divide object into 3 sections:
    Section 1 vertices: 0,1,2,3
    Section 2 vertices: 2,3,4
    Section 3 vertices: 5,6,7,8
    */
    // Section 1
    glColor3ub(211,6,2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(initObj[0][0],initObj[0][1]);
        glVertex2f(initObj[1][0],initObj[1][1]);
        glVertex2f(initObj[2][0],initObj[2][1]);
        glVertex2f(initObj[3][0],initObj[3][1]);
    glEnd();

    // Section 2
    glBegin(GL_LINE_LOOP);
        glVertex2f(initObj[2][0],initObj[2][1]);
        glVertex2f(initObj[3][0],initObj[3][1]);
        glVertex2f(initObj[4][0],initObj[4][1]);
    glEnd();

    // Section 3
    glBegin(GL_LINE_LOOP);
        glVertex2f(initObj[5][0],initObj[5][1]);
        glVertex2f(initObj[6][0],initObj[6][1]);
        glVertex2f(initObj[7][0],initObj[7][1]);
        glVertex2f(initObj[8][0],initObj[8][1]);
    glEnd();
    glFlush();

}

void rotate(){

    theta = (theta * 3.14)/180;

    rotMatrix[0][0] = cos(theta);
    rotMatrix[0][1] = sin(theta);
    rotMatrix[0][2] = 0;
    rotMatrix[1][0] = -sin(theta);
    rotMatrix[1][1] = cos(theta);
    rotMatrix[1][2] = 0;
    rotMatrix[2][0] = cos(theta);
    rotMatrix[2][1] = cos(theta);
    rotMatrix[2][2] = cos(theta);

    for (p = 0; p<9; p++){
        for (q = 0; q<9; q++){
            resObj[p][q]=0;
            for (r = 0; r<3; r++){
                resObj[p][q] += (initObj[p][r] * rotMatrix[r][q]);
            }
        }
    }
}
void display(){
    drawInitialObj();
}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(600,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Poly Fill");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
