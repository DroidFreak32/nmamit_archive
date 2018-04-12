// Display point
#include <GL/glut.h>
#include<GL/gl.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include "RGBpixmap.h"

// For PRNG
#include <time.h>
using namespace std;

// For sleep functions
#include <chrono>
#include <thread>

int sceneNum = 0;
long CLOSETHREAD = 0;
RGBpixmap pix[100];
char textDisp[100]="Humpty Dumpty sat on a wall";

void *playBGMusic( void *threadid ){

    long tid;
   tid = (long)threadid;
    system("canberra-gtk-play -f cgmusic.wav --volume=0.02 --loop=10");
    if(CLOSETHREAD == 1){
        pthread_exit(NULL);
    }
    pthread_exit(NULL);
    
}

// void playSongMusic1(){
//     system("canberra-gtk-play -f  humptyfull1.wav --volume=7");
// }

// void playSongMusic2(){
//     system("canberra-gtk-play -f  humptyfull2.wav");
// }

// void playSongMusic3(){
//     system("canberra-gtk-play -f  humptyfull3.wav");
// }

// void playSongMusic4(){
//     system("canberra-gtk-play -f  humptyfull4.wav");
// }

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
    glClearColor(0/255.0f,0/255.0f,18/255.0f,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glutSwapBuffers();
}


void drawWallBricks(int increaseHeight){
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

    if (sceneNum == 2 && increaseHeight > 15){
        glBegin(GL_POLYGON);
            glVertex2d(850,30 +increaseHeight);
            glVertex2d(850,80 +increaseHeight);
            glVertex2d(750,80 +increaseHeight);
            glVertex2d(750,30 +increaseHeight);
            glVertex2d(850,30 +increaseHeight);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2d(735,30 +increaseHeight);
            glVertex2d(735,80 +increaseHeight);
            glVertex2d(635,80 +increaseHeight);
            glVertex2d(635,30 +increaseHeight);
            glVertex2d(735,30 +increaseHeight);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2d(800,-35 +increaseHeight);
            glVertex2d(800,15 +increaseHeight);
            glVertex2d(700,15 +increaseHeight);
            glVertex2d(700,-35 +increaseHeight);
            glVertex2d(800,-35 +increaseHeight);
        glEnd();



        glBegin(GL_POLYGON);
            glVertex2d(550,-100 +increaseHeight);
            glVertex2d(550,-50 +increaseHeight);
            glVertex2d(450,-50 +increaseHeight);
            glVertex2d(450,-100 +increaseHeight);
            glVertex2d(550,-100 +increaseHeight);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2d(435,-100 +increaseHeight);
            glVertex2d(435,-50 +increaseHeight);
            glVertex2d(335,-50 +increaseHeight);
            glVertex2d(335,-100 +increaseHeight);
            glVertex2d(435,-100 +increaseHeight);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2d(500,-165 +increaseHeight);
            glVertex2d(500,-115 +increaseHeight);
            glVertex2d(400,-115 +increaseHeight);
            glVertex2d(400,-165 +increaseHeight);
            glVertex2d(500,-165 +increaseHeight);
        glEnd();



        // Base Brick Left
    glColor3ub(140,43,55);
    glBegin(GL_POLYGON);
        glVertex2d(300,-350 +increaseHeight);
        glVertex2d(300,-300 +increaseHeight);
        glVertex2d(400,-300 +increaseHeight);
        glVertex2d(400,-350 +increaseHeight);
        glVertex2d(300,-350 +increaseHeight);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(415,-350 +increaseHeight);
        glVertex2d(415,-300 +increaseHeight);
        glVertex2d(515,-300 +increaseHeight);
        glVertex2d(515,-350 +increaseHeight);
        glVertex2d(415,-350 +increaseHeight);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(350,-415 +increaseHeight);
        glVertex2d(350,-365 +increaseHeight);
        glVertex2d(450,-365 +increaseHeight);
        glVertex2d(450,-415 +increaseHeight);
        glVertex2d(350,-415 +increaseHeight);
    glEnd();

    // Base Brick Right
    glBegin(GL_POLYGON);
        glVertex2d(960,-220 +increaseHeight);
        glVertex2d(960,-170 +increaseHeight);
        glVertex2d(860,-170 +increaseHeight);
        glVertex2d(860,-220 +increaseHeight);
        glVertex2d(960,-220 +increaseHeight);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(845,-220 +increaseHeight);
        glVertex2d(845,-170 +increaseHeight);
        glVertex2d(745,-170 +increaseHeight);
        glVertex2d(745,-220 +increaseHeight);
        glVertex2d(845,-220 +increaseHeight);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(910,-285 +increaseHeight);
        glVertex2d(910,-235 +increaseHeight);
        glVertex2d(810,-235 +increaseHeight);
        glVertex2d(810,-285 +increaseHeight);
        glVertex2d(910,-285 +increaseHeight);
    glEnd();
    }

}

//copy poly for wall
void drawWall(int increaseHeight){

    glColor3ub(203,65,84);
    glBegin(GL_POLYGON);
        glVertex2d(250,0);
        glVertex2d(250,300+increaseHeight);
        glVertex2d(1000,300+increaseHeight);
        glVertex2d(1000,0);
        glVertex2d(250,0);
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

    drawWallBricks(increaseHeight);

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
    
    glFlush();

}

void drawFactoryLights(int extraheight){

    glColor3ub(255,0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex2d(185,124+extraheight);
        glVertex2d(190,124+extraheight);
    glEnd();
    glColor3ub(255,241,118);
    glPointSize(3);
    glBegin(GL_POINTS);

    // For the Extra Floors
        glVertex2d(37,57+extraheight);
        glVertex2d(87,57+extraheight);
        glVertex2d(122,57+extraheight);
        glVertex2d(152,57+extraheight);
        glVertex2d(182,57+extraheight);
        glVertex2d(182,69+extraheight);
        glVertex2d(182,81+extraheight);
        glVertex2d(182,93+extraheight);
        glVertex2d(212,57+extraheight);
    // For the rest
    for (int i = 0; i<=200; i+=13){
        glVertex2d(12,45-i+extraheight);
        glVertex2d(37,45-i+extraheight);
        glVertex2d(62,45-i+extraheight);
        glVertex2d(87,45-i+extraheight);
        glVertex2d(122,45-i+extraheight);
        glVertex2d(152,45-i+extraheight);
        glVertex2d(182,45-i+extraheight);
        glVertex2d(212,45-i+extraheight);
        glVertex2d(232,45-i+extraheight);
    }
    glEnd();
}

void drawFactory(int extraheight){

    glColor3ub(21,21,21);
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

    drawFactoryLights(extraheight);
    glFlush();

}


void drawText(char *string, int rr, int gg, int bb) {

    //get the length of the string to display
    int len = (int) strlen(string);

    glColor3ub(rr,gg,bb);

    //set the position of the text in the window using the x and y coordinates
    glRasterPos2i(350,950);

    glDisable(GL_LIGHTING);
    //loop to display character by character
    for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
    // glEnable(GL_LIGHTING);
    glFlush();
}


void drawGrass(){
    //Granite
    glColor3ub(31, 138, 19);
    for (int x=0; x<1000; x+=50){
        glBegin(GL_POLYGON);
            glVertex2d(x,50);
            glVertex2d(x+25,75+(rand()%363)%50);
            glVertex2d(x+50,50);
        glEnd();
    }
}

void drawGround(){
    //Granite
    glColor3ub(162,162,161);
    glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(0,50);
        glVertex2d(1000,50);
        glVertex2d(1000,0);
        glVertex2d(0,0);
    glEnd();
    drawGrass();
}

void drawFullWall(){
    glColor3ub(203,65,84);
    glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(0,1000);
        glVertex2d(1000,1000);
        glVertex2d(1000,0);
        glVertex2d(0,0);
    glEnd();
}

void drawStars(){

    glRasterPos2i(700, 700);
    pix[9].draw();

    glColor3ub(200, 200, 200);
    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex2d(12,825);
        glVertex2d(27,821);
        glVertex2d(50,100);
        glVertex2d(55,150);
        glVertex2d(55,420);
        glVertex2d(66,220);
        glVertex2d(68,395);
        glVertex2d(75,896);
        glVertex2d(100,900);
        glVertex2d(119,790);
        glVertex2d(123,803);
        glVertex2d(131,864);
        glVertex2d(158,989);
        glVertex2d(201,606);
        glVertex2d(206,645);
        glVertex2d(208,897);
        glVertex2d(214,496);
        glVertex2d(222,190);
        glVertex2d(223,719);
        glVertex2d(238,418);
        glVertex2d(263,614);
        glVertex2d(307,138);
        glVertex2d(308,646);
        glVertex2d(350,638);
        glVertex2d(356,477);
        glVertex2d(362,439);
        glVertex2d(378,446);
        glVertex2d(380,422);
        glVertex2d(399,652);
        glVertex2d(400,813);
        glVertex2d(417,869);
        glVertex2d(438,753);
        glVertex2d(453,656);
        glVertex2d(503,846);
        glVertex2d(520,646);
        glVertex2d(542,836);
        glVertex2d(547,477);
        glVertex2d(548,527);
        glVertex2d(556,669);
        glVertex2d(591,496);
        glVertex2d(616,395);
        glVertex2d(653,568);
        glVertex2d(658,439);
        glVertex2d(669,652);
        glVertex2d(673,418);
        glVertex2d(719,490);
        glVertex2d(719,979);
        glVertex2d(731,527);
        glVertex2d(757,533);
        glVertex2d(773,958);
        glVertex2d(789,534);
        glVertex2d(798,946);
        glVertex2d(799,870);
        glVertex2d(803,457);
        glVertex2d(813,851);
        glVertex2d(821,433);
        glVertex2d(825,485);
        glVertex2d(836,779);
        glVertex2d(864,329);
        glVertex2d(879,757);
        glVertex2d(896,482);
        glVertex2d(897,492);
        glVertex2d(901,814);
        glVertex2d(943,864);
        glVertex2d(964,737);
        glVertex2d(969,651);
        glVertex2d(976,758);
        glVertex2d(989,308);
        glVertex2d(990,284);
    glEnd();
}

void mouse_func(int button, int state, int x, int y){

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        sceneNum++;
        glutPostRedisplay();
        
    }
}

void keyboard_func(int key,int x, int y){

    switch(key){
        case GLUT_KEY_RIGHT:
            sceneNum++;
            break;
        case GLUT_KEY_UP:
            sceneNum++;
            break;
        case GLUT_KEY_LEFT:
            sceneNum--;
            break;
        case GLUT_KEY_DOWN:
            sceneNum--;
            break;
    }
    glutPostRedisplay();
}


void keyboard1_func(unsigned char key, int x, int y){

    if (key == 'q')
    {
        system("killall canberra-gtk-play");
        exit(0);
    }
}
void menuActions(int value){
    switch (value){
        case 1:
            sceneNum = 0;
            glutPostRedisplay();
            break;
        case 2:
            sceneNum = 1;
            glutPostRedisplay();
            break;
        case 3:
            sceneNum = 2;
            glutPostRedisplay();
            break;
        case 4:
            sceneNum = 3;
            glutPostRedisplay();
            break;
        case 5:
            system("killall canberra-gtk-play");
            exit(0);
            break;
    }
}



void display(){
    printf("Scene number: %d\n", sceneNum);
    // clear_screen();
    if(sceneNum == 0){
        strcpy(textDisp,"Humpty Dumpty sat on a wall.");
        clear_screen();
        drawStars();
        drawWall(0);
        drawFactory(0);
        drawText(textDisp,255,0,0);
        glRasterPos2i(400, 275);
        pix[0].draw();
        glutSwapBuffers();
        glFlush();

    }
    if(sceneNum == 1){
        strcpy(textDisp,"Humpty Dumpty had a great fall.");
        int fallHumptyY = 275;
        while(fallHumptyY >= 0){
            // glTranslated(0, -2, 0);
            clear_screen();
            drawWall(0);
            drawStars();
            drawFactory(0);
            drawText(textDisp,0,230,118);
            fallHumptyY-=5;
            glRasterPos2i(400, fallHumptyY);
            if (fallHumptyY > 250){
                pix[0].draw();
            }
            else{
                pix[1].draw();
            }
            glFlush();
            glutSwapBuffers();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
    if(sceneNum == 2){
        strcpy(textDisp,"All the king's horses and all the king's men..");
        int increaseHeight = 0;
        while (increaseHeight < 630){
            clear_screen();
            drawStars();
            increaseHeight +=30;
            drawWall(increaseHeight);
            glFlush();
            glutSwapBuffers();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        drawFactory(200);
        drawText(textDisp,255,145,0);
        drawGround();
        glRasterPos2i(800, 5);
        pix[2].draw();
        glRasterPos2i(100, 5);
        pix[3].draw();
        glRasterPos2i(700, 5);
        pix[4].draw();
        glRasterPos2i(150, 5);
        pix[5].draw();
        glRasterPos2i(600, 5);
        pix[6].draw();
        glRasterPos2i(300, 0);
        pix[7].draw();
        glutSwapBuffers();
    }
    if(sceneNum == 3){
        strcpy(textDisp,"Couldn't put humpty together again.");
        clear_screen();
        int increaseHeight = 600;
        while (increaseHeight > -29){
            clear_screen();
            drawStars();
            increaseHeight -=30;
            drawWall(increaseHeight);
            glFlush();
            glutSwapBuffers();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        drawFactory(0);
        drawText(textDisp,255,255,0);
        glRasterPos2i(400, 275);
        pix[8].draw();
        glutSwapBuffers();
    }
}

void monitorSceneNum(){
    if (sceneNum > 4){
        sceneNum = 4;
    }
}
int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Basic Window");
    pix[0].readBMPFile("EggmanSits.bmp",true);
    pix[1].readBMPFile("EggmanFallz.bmp",true);
    pix[2].readBMPFile("horse1-small.bmp",true);
    pix[3].readBMPFile("horse1-small-mirror.bmp",true);
    pix[4].readBMPFile("King_SnU.bmp",true);
    pix[5].readBMPFile("King_SnU_mirror.bmp",true);
    pix[6].readBMPFile("knight.bmp",true);
    pix[7].readBMPFile("DeadmanEggman.bmp",true);
    pix[8].readBMPFile("SaddenedEggman.bmp",true);
    pix[9].readBMPFile("moon.bmp",true);
    init();
    // std::thread t1(playBGMusic);
    pthread_t tid;
    pthread_create(&tid, NULL,&playBGMusic , (void *) CLOSETHREAD);
    glutMouseFunc(mouse_func);
    glutSpecialFunc(keyboard_func);
    glutKeyboardFunc(keyboard1_func);
    glutDisplayFunc(display);
    glutIdleFunc(monitorSceneNum);
    glutCreateMenu(menuActions);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutAddMenuEntry("Goto Scene 1", 1);
    glutAddMenuEntry("Goto Scene 2", 2);
    glutAddMenuEntry("Goto Scene 3", 3);
    glutAddMenuEntry("Goto Scene 4", 4);
    glutAddMenuEntry("Exit", 5);
    glutMainLoop();
    // t1.join();
    pix[0].freeIt();
    pix[1].freeIt();
    pix[2].freeIt();
    pix[3].freeIt();
    pix[4].freeIt();
    pix[5].freeIt();
    pix[6].freeIt();
    pix[7].freeIt();
    pix[8].freeIt();
    pix[9].freeIt();
    return 0;
}

