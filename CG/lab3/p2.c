// Display circle
#include <GL/glut.h>
#include <stdio.h>
#include <GL/freeglut.h>
void init();
void maindisplay();
void display();
void midpointCircle();

int rad;

void init(){
    gluOrtho2D(-100,100,-100,100);
}

void maindisplay(){

    glClearColor(0,0,0,0); // RGB-A Specify the color. Won't Change the color
    glClear(GL_COLOR_BUFFER_BIT); // Removes the color from COLOR_BUFFER_BIT after removing everything it'll fill the buffer with specified color
    glPointSize(5);
    //midpointCircle(2,2,50,50);
    midpointCircle();
    glFlush(); //Each one is rendered in a proper manner. (Here.. Finishes the job of the above functions)
}

void putpixel(int x, int y){
        // glColor3f(r,g,b) Specifying color to any object
    glColor3f(0.0,0.0,1.0);
    glPointSize(5);
    glBegin(GL_POINTS); // Draw Lines. Only 2 verteices.
        glVertex2f(x,y);
        glVertex2f(x,-y);
        glVertex2f(-x,y);
        glVertex2f(-x,-y);
        glVertex2f(y,x);
        glVertex2f(y,-x);
        glVertex2f(-y,-x);
        glVertex2f(-y,x);
    glEnd();

}
//void midpointCircle(int X0, int Y0, int X1, int Y1){
void midpointCircle(){
    
    int x = 0;
    int y = rad;
    float d = ((5.0/4.0) - rad);
    putpixel(x,y);
    while(x <= y){
        if (d <= 0)
            d += (2*x) + 3;
        else {
            d += (2*(x-y) + 5);
            y--;
        }
        x++;
        putpixel(x,y);
    }

}


int main(int argc,char *argv[]){

    printf("Enter radius : ");
    scanf("%d", &rad);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(70,70);
    glutInit(&argc,argv);
    glutCreateWindow("Basic Window");
    init();
    glutDisplayFunc(maindisplay); // Resize with and without the function see the diff
    // display();

     // glutDisplayFunc(display2); Here disp2 overlapps disp1 so disp1 cannot be seen


    glutMainLoop();
    return 0;
}


//glutDisplayFunc(display_func_name) mandatory to invoke any function
