// Display point
#include <GL/glut.h>
void init();
void maindisplay();
void display();
void maindisplay(){

    // glColor3f(r,g,b) Specifying color to any object
    glColor3f(0.0,0.0,1.0);
    glLineWidth(2);
    glBegin(GL_LINES); // Draw Lines. Only 2 verteices.

        //Specify the points coordinates b/w -1 & 1
        glVertex2f(-1,0);
        glVertex2f(1,0);
        glVertex2f(0,-1);
        glVertex2f(0,1);

    glEnd();
    glFlush();
    display();
}

void display(){

    // glColor3f(r,g,b) Specifying color to any object
    glColor3f(1.0,1.0,1.0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP); // Draw Lines. Only 2 verteices.
        //Specify the points coordinates b/w -1 & 1      
        glVertex2f(0.75,0.75);
        glVertex2f(0.75,-0.75);
        glVertex2f(-0.75,-0.75);
        glVertex2f(-0.75,0.75);
    glEnd();

    glBegin(GL_LINE_LOOP); // Draw Lines. Only 2 verteices.
        //Specify the points coordinates b/w -1 & 1      
        glVertex2f(0,0.75);
        glVertex2f(0.75,0);
        glVertex2f(0,-0.75);
        glVertex2f(-0.75,0);
    glEnd();

    glBegin(GL_LINE_LOOP); // Draw Lines. Only 2 verteices.
        //Specify the points coordinates b/w -1 & 1      
        glVertex2f(0.375,0.375);
        glVertex2f(0.375,-0.375);
        glVertex2f(-0.375,-0.375);
        glVertex2f(-0.375,0.375);
    glEnd();


    glBegin(GL_LINE_LOOP); // Draw Lines. Only 2 verteices.
        //Specify the points coordinates b/w -1 & 1      
        glVertex2f(0,0.375);
        glVertex2f(0.375,0);
        glVertex2f(0,-0.375);
        glVertex2f(-0.375,0);
    glEnd();

    glBegin(GL_LINE_LOOP); // Draw Lines. Only 2 verteices.
        //Specify the points coordinates b/w -1 & 1      
        glVertex2f(0.75,0.75);
        glVertex2f(0.75,-0.75);
        glVertex2f(-0.75,-0.75);
        glVertex2f(-0.75,0.75);
    glEnd();

    glFlush();
    // display1();
}


int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(70,70);
    glutCreateWindow("Basic Window");
    init();
    glutDisplayFunc(maindisplay); // Resize with and without the function see the diff
    // display();

     // glutDisplayFunc(display2); Here disp2 overlapps disp1 so disp1 cannot be seen


    glutMainLoop();
    return 0;
}


void init(){
    glClearColor(0,0,0,0); // RGB-A Specify the color. Won't Change the color
    glClear(GL_COLOR_BUFFER_BIT); // Removes the color from COLOR_BUFFER_BIT after removing everything it'll fill the buffer with specified color
    glFlush(); //Each one is rendered in a proper manner. (Here.. Finishes the job of the above functions)    
}

//glutDisplayFunc(display_func_name) mandatory to invoke any function