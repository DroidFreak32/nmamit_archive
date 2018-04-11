// Display point
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
using namespace std;

void init()
{
    glClearColor(129/255.0f,212/255.0f,250/255.0f,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1000,0,1000); // Left Right Bottom Top
    glFlush();
}
//glutDisplayFunc(display_func_name) mandatory to invoke any function

void clear_screen(){
    glClearColor(3/255.0f,155/255.0f,229/255.0f,1.0);
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

//copy poly for wall
void drawWall(){

    // clear_screen();
    // Base
    glColor3ub(203,65,84);
    glBegin(GL_POLYGON);
        glVertex2d(250,0);
        glVertex2d(250,300);
        glVertex2d(1000,300);
        glVertex2d(1000,0);
        glVertex2d(250,0);
    glEnd();

    // Base Brick Left
    glColor3ub(140,43,55);
    glBegin(GL_POLYGON);
        glVertex2d(300,200);
        glVertex2d(300,250);
        glVertex2d(400,250);
        glVertex2d(400,200);
        glVertex2d(300,200);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(415,200);
        glVertex2d(415,250);
        glVertex2d(515,250);
        glVertex2d(515,200);
        glVertex2d(415,200);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(350,135);
        glVertex2d(350,185);
        glVertex2d(450,185);
        glVertex2d(450,135);
        glVertex2d(350,135);
    glEnd();

    // Base Brick Right
    glBegin(GL_POLYGON);
        glVertex2d(950,200);
        glVertex2d(950,250);
        glVertex2d(850,250);
        glVertex2d(850,200);
        glVertex2d(950,200);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(835,200);
        glVertex2d(835,250);
        glVertex2d(735,250);
        glVertex2d(735,200);
        glVertex2d(835,200);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(900,135);
        glVertex2d(900,185);
        glVertex2d(800,185);
        glVertex2d(800,135);
        glVertex2d(900,135);
    glEnd();

    //Granite
    glColor3ub(162,162,161);
    glBegin(GL_POLYGON);
        glVertex2d(200,300);
        glVertex2d(200,325);
        glVertex2d(1000,325);
        glVertex2d(1000,300);
        glVertex2d(200,300);
    glEnd();

    // Granite bricks
    glColor3ub(77,77,77);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex2d(300,300);
        glVertex2d(300,325);
        glVertex2d(400,300);
        glVertex2d(400,325);
        glVertex2d(500,300);
        glVertex2d(500,325);
        glVertex2d(600,300);
        glVertex2d(600,325);
        glVertex2d(700,300);
        glVertex2d(700,325);
        glVertex2d(800,300);
        glVertex2d(800,325);
        glVertex2d(900,300);
        glVertex2d(900,325);
    glEnd();
    glFlush();

}

void drawFactory(){

    glColor3ub(33,33,33);
    glBegin(GL_POLYGON);
        glVertex2d(0,50);
        glVertex2d(50,75);
        glVertex2d(50,0);
        glVertex2d(0,0);
        glVertex2d(0,50);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(50,50);
        glVertex2d(100,70);
        glVertex2d(100,0);
        glVertex2d(50,0);
        glVertex2d(50,50);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(100,50);
        glVertex2d(125,75);
        glVertex2d(225,75);
        glVertex2d(250,50);
        glVertex2d(250,0);
        glVertex2d(100,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(175,0);
        glVertex2d(175,100);
        glVertex2d(200,100);
        glVertex2d(200,0);
    glEnd();
    //tower
    glBegin(GL_POLYGON);
        glVertex2d(185,100);
        glVertex2d(185,125);
        glVertex2d(190,125);
        glVertex2d(190,100);      
    glEnd();

}


void drawText(char *string) {

    //get the length of the string to display
    int len = (int) strlen(string);

    glColor3ub(255,20,20);

    //set the position of the text in the window using the x and y coordinates
    glRasterPos2i(100,800);

    glDisable(GL_LIGHTING);
    //loop to display character by character
    for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
    glEnable(GL_LIGHTING);
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
 void display(){
    drawWall();
    drawFactory();
    char string[100]="Humpty Dumpty sat on a wall";
    drawText(string);
    glFlush();
 }
int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1000,1000);
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

