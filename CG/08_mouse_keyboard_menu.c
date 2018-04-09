// Display point
#include <GL/glut.h>
#include <stdio.h>


void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,500,0); // Left Right Bottom Top
    glFlush();
}
//glutDisplayFunc(display_func_name) mandatory to invoke any function

void clear_screen(){
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
void drawSquare(int x, int y){

    clear_screen();
    printf("Coordinates are: %d\t%d\n",x,y);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y);
        glVertex2f(x+100,y);
        glVertex2f(x+100,y-100);
        glVertex2f(x,y-100);
    glEnd();
    glFlush();

}
void drawPolygon(int x, int y){

    clear_screen();
    printf("Coordinates are: %d\t%d\n",x,y);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+100,y);
        glVertex2f(x+150,y-50);
        glVertex2f(x+100,y-100);
        glVertex2f(x,y-100);
        glVertex2f(x-50,y-50);
        glVertex2f(x,y);
    glEnd();
    glFlush();

}
void drawTriangle(int x, int y){
    clear_screen();
    printf("Triangle initial Coordinates are: %d\t%d\n",x,y);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y);
        glVertex2f(x-30,y+100);
        glVertex2f(x+30,y+100);

    glEnd();
    glFlush();
}
void drawPoint(int x, int y){
    clear_screen();
    printf("Point coordinates are: %d\t%d\n",x,y);
    glColor3f(1.0,0.0,1.0);
    glPointSize(9);
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
    glFlush();
}

void mouse_func(int button, int state, int x, int y){

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        drawSquare(x,y);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        drawPoint(x,y);
}
void keyboard_func(unsigned char key, int x, int y){

    if (key == 't' || key == 'T')
        drawTriangle(x,y);
    if (key == 'p' || key == 'P')
        drawPolygon(x,y);
}


void menuActions(int value){
    if (value == 1)
        drawSquare(100,200);
    if (value == 2)
        exit(0);

}
 void display(){}
int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Basic Window");
    init();
    glutMouseFunc(mouse_func);
    glutKeyboardFunc(keyboard_func);
    glutDisplayFunc(display);
    glutCreateMenu(menuActions);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutAddMenuEntry("Display Rectangle", 1); //Name and Value. Value is sent to menuAction()
    glutAddMenuEntry("Exit", 2);

    glutMainLoop();
    return 0;
}

