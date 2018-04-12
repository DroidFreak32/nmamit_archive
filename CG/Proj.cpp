// Display point
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "RGBpixmap.h"
#define OGL 1
using namespace std;
#include <chrono>
#include <thread>

int sceneNum = 0;
RGBpixmap pix[2];
char textDisp[100]="Humpty Dumpty sat on a wall";
void init()
{
    glClearColor(129/255.0f,212/255.0f,250/255.0f,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1000,0,1000); // Left Right Bottom Top
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1.0);
    glFlush();
}
//glutDisplayFunc(display_func_name) mandatory to invoke any function

void clear_screen(){
    glClearColor(3/255.0f,155/255.0f,229/255.0f,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glutSwapBuffers();
}

//copy poly for wall
void drawWall(int increaseHeight){

    if (sceneNum == 99 || sceneNum == 99){
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
    }
    else {
        glColor3ub(203,65,84);
        glBegin(GL_POLYGON);
            glVertex2d(250,0);
            glVertex2d(250,300+increaseHeight);
            glVertex2d(1000,300+increaseHeight);
            glVertex2d(1000,0);
            glVertex2d(250,0);
        glEnd();

        // Base Brick Left
        glColor3ub(140,43,55);
        glBegin(GL_POLYGON);
            glVertex2d(300,200+increaseHeight);
            glVertex2d(300,250+increaseHeight);
            glVertex2d(400,250+increaseHeight);
            glVertex2d(400,200+increaseHeight);
            glVertex2d(300,200+increaseHeight);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2d(415,200+increaseHeight);
            glVertex2d(415,250+increaseHeight);
            glVertex2d(515,250+increaseHeight);
            glVertex2d(515,200+increaseHeight);
            glVertex2d(415,200+increaseHeight);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2d(350,135+increaseHeight);
            glVertex2d(350,185+increaseHeight);
            glVertex2d(450,185+increaseHeight);
            glVertex2d(450,135+increaseHeight);
            glVertex2d(350,135+increaseHeight);
        glEnd();

        // Base Brick Right
        glBegin(GL_POLYGON);
            glVertex2d(950,200+increaseHeight);
            glVertex2d(950,250+increaseHeight);
            glVertex2d(850,250+increaseHeight);
            glVertex2d(850,200+increaseHeight);
            glVertex2d(950,200+increaseHeight);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2d(835,200+increaseHeight);
            glVertex2d(835,250+increaseHeight);
            glVertex2d(735,250+increaseHeight);
            glVertex2d(735,200+increaseHeight);
            glVertex2d(835,200+increaseHeight);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2d(900,135+increaseHeight);
            glVertex2d(900,185+increaseHeight);
            glVertex2d(800,185+increaseHeight);
            glVertex2d(800,135+increaseHeight);
            glVertex2d(900,135+increaseHeight);
        glEnd();

        //Granite
        glColor3ub(162,162,161);
        glBegin(GL_POLYGON);
            glVertex2d(200,300+increaseHeight);
            glVertex2d(200,325+increaseHeight);
            glVertex2d(1000,325+increaseHeight);
            glVertex2d(1000,300+increaseHeight);
            glVertex2d(200,300+increaseHeight);
        glEnd();

        // Granite bricks
        glColor3ub(77,77,77);
        glLineWidth(3);
        glBegin(GL_LINES);
            glVertex2d(300,300+increaseHeight);
            glVertex2d(300,325+increaseHeight);
            glVertex2d(400,300+increaseHeight);
            glVertex2d(400,325+increaseHeight);
            glVertex2d(500,300+increaseHeight);
            glVertex2d(500,325+increaseHeight);
            glVertex2d(600,300+increaseHeight);
            glVertex2d(600,325+increaseHeight);
            glVertex2d(700,300+increaseHeight);
            glVertex2d(700,325+increaseHeight);
            glVertex2d(800,300+increaseHeight);
            glVertex2d(800,325+increaseHeight);
            glVertex2d(900,300+increaseHeight);
            glVertex2d(900,325+increaseHeight);
        glEnd();        
    }
    glFlush();

}

void drawWallIncreasing(int increaseHeight){


}
void drawFactory(int extraheight){

    glColor3ub(33,33,33);
    glBegin(GL_POLYGON);
        glVertex2d(0,50+extraheight);
        glVertex2d(50,75+extraheight);
        glVertex2d(50,0);
        glVertex2d(0,0);
        glVertex2d(0,50+extraheight);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(50,50+extraheight);
        glVertex2d(100,70+extraheight);
        glVertex2d(100,0);
        glVertex2d(50,0);
        glVertex2d(50,50+extraheight);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(100,50+extraheight);
        glVertex2d(125,75+extraheight);
        glVertex2d(225,75+extraheight);
        glVertex2d(250,50+extraheight);
        glVertex2d(250,0);
        glVertex2d(100,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(175,0);
        glVertex2d(175,100+extraheight);
        glVertex2d(200,100+extraheight);
        glVertex2d(200,0);
    glEnd();
    //tower
    glBegin(GL_POLYGON);
        glVertex2d(185,100+extraheight);
        glVertex2d(185,125+extraheight);
        glVertex2d(190,125+extraheight);
        glVertex2d(190,100+extraheight);
    glEnd();
    glFlush();

}


void drawText(char *string, int rr, int gg, int bb) {

    //get the length of the string to display
    int len = (int) strlen(string);

    glColor3ub(rr,gg,bb);

    //set the position of the text in the window using the x and y coordinates
    glRasterPos2i(400,950);

    glDisable(GL_LIGHTING);
    //loop to display character by character
    for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
    // glEnable(GL_LIGHTING);
    glFlush();
}


void mouse_func(int button, int state, int x, int y){

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        sceneNum++;
        glutPostRedisplay();
    }
}

/*
void menuActions(int value){
    if (value == 1)
        drawSquare(100,200);
    if (value == 2)
        exit(0);

}
*/
 void display(){
    printf("Scene number: %d\n", sceneNum);
    // clear_screen();
    if(sceneNum == 0){
        clear_screen();
        drawWall(0);
        drawFactory(0);
        drawText(textDisp,255,0,0);
        glRasterPos2i(400, 306);
        pix[0].draw();
        glutSwapBuffers();
    }
    if(sceneNum == 1){
        strcpy(textDisp,"Humpty Dumpty had a great fall");
        int fallHumptyY = 306;
        while(fallHumptyY > 0){
            // glTranslated(0, -2, 0);
            clear_screen();
            drawWall(0);
            drawFactory(0);
            drawText(textDisp,255,0,0);
            fallHumptyY-=5;
            glRasterPos2i(400, fallHumptyY);
            printf("Fall number: %d\n", fallHumptyY);
            pix[0].draw();
            glFlush();
            glutSwapBuffers();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
    if(sceneNum == 2){
        strcpy(textDisp,"All the horses and all the king's men..");
        int increaseHeight = 0;
        while (increaseHeight < 630){
            clear_screen();
            increaseHeight +=30;
            drawWall(increaseHeight);
            glFlush();
            glutSwapBuffers();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        drawFactory(200);
        drawText(textDisp,255,0,0);
        glRasterPos2i(800, 5);
        pix[1].draw();
        glRasterPos2i(50, 5);
        pix[2].draw();
        glRasterPos2i(700, 5);
        pix[3].draw();
        glRasterPos2i(200, 5);
        pix[4].draw();
        glRasterPos2i(600, 5);
        pix[5].draw();
        glutSwapBuffers();
    }
    if(sceneNum == 3){
        clear_screen();
        strcpy(textDisp,"Couldn't put Humpty together again.");
        drawWall(600);
        drawFactory(200);
        drawText(textDisp,255,0,0);
        glRasterPos2i(800, 5);
        pix[1].draw();
        glRasterPos2i(50, 5);
        pix[2].draw();
        glRasterPos2i(700, 5);
        pix[3].draw();
        glRasterPos2i(200, 5);
        pix[4].draw();
        glRasterPos2i(600, 5);
        pix[5].draw();
        glFlush();
        glutSwapBuffers();
    }
    glFlush();
 }
int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Basic Window");
    pix[0].readBMPFile("smallhumpty.bmp",true);
    pix[1].readBMPFile("horse1-small.bmp",true);
    pix[2].readBMPFile("horse1-small-mirror.bmp",true);
    pix[3].readBMPFile("King_SnU.bmp",true);
    pix[4].readBMPFile("King_SnU_mirror.bmp",true);
    pix[5].readBMPFile("knight.bmp",true);
    init();
    glutMouseFunc(mouse_func);
    // glutKeyboardFunc(keyboard_func);
    glutDisplayFunc(display);
    // glutCreateMenu(menuActions);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutAddMenuEntry("Display Rectangle", 1); //Name and Value. Value is sent to menuAction()
    glutAddMenuEntry("Exit", 2);
    glutMainLoop();
    return 0;
}

