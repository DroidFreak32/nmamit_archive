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
float resObj[9][3],rotMatrix[3][3],theta,xp=200,yp=200;

int p,q,r;
void init(){
    glClearColor(0,0,0,0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

void drawInitialObj( float mat[9][3]){
    /*
    Divide object into 3 sections:
    Section 1 vertices: 0,1,2,3
    Section 2 vertices: 2,3,4
    Section 3 vertices: 5,6,7,8
    */
    // Section 1
    glColor3ub(211,6,2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(mat[0][0],mat[0][1]);
        glVertex2f(mat[1][0],mat[1][1]);
        glVertex2f(mat[2][0],mat[2][1]);
        glVertex2f(mat[3][0],mat[3][1]);
    glEnd();

    // Section 2
    glBegin(GL_LINE_LOOP);
        glVertex2f(mat[2][0],mat[2][1]);
        glVertex2f(mat[3][0],mat[3][1]);
        glVertex2f(mat[4][0],mat[4][1]);
    glEnd();

    // Section 3
    glBegin(GL_LINE_LOOP);
        glVertex2f(mat[5][0],mat[5][1]);
        glVertex2f(mat[6][0],mat[6][1]);
        glVertex2f(mat[7][0],mat[7][1]);
        glVertex2f(mat[8][0],mat[8][1]);
    glEnd();
    glFlush();

}

void rotate(){

    theta = (90 * 3.14)/180;
    float m = (-xp * cos(theta))+(yp*sin(theta))+xp;
    float n = (-xp * sin(theta))-(yp*cos(theta))+yp;
    rotMatrix[0][0] = cos(theta);
    rotMatrix[0][1] = sin(theta);
    rotMatrix[0][2] = 0;
    rotMatrix[1][0] = -sin(theta);
    rotMatrix[1][1] = cos(theta);
    rotMatrix[1][2] = 0;
    rotMatrix[2][0] = m;
    rotMatrix[2][1] = n;
    rotMatrix[2][2] = 1;

    for (p = 0; p<9; p++){
        for (q = 0; q<3; q++){
            resObj[p][q]=0;
            for (r = 0; r<3; r++){
                resObj[p][q] = resObj[p][q] + (initObj[p][r] * rotMatrix[r][q]);
                if (resObj[p][q] == initObj[p][q])
                printf("Eq\n");
            }
        }
    }
}
void display(){
    drawInitialObj(initObj);
    rotate();
    printf("domnee1");
    drawInitialObj(resObj);
    for (int i =0; i<9;i++)
    {printf("\n");
for (int j =0; j<3;j++)
printf("%lf=%lf\t",initObj[i][j],resObj[i][j]);
    }
    // glFlush();
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
