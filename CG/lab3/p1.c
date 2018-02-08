// Display midpoint line
#include <GL/glut.h>
#include <stdio.h>
#include <GL/freeglut.h>
void init();
void maindisplay();
void display();
void midpointLine();

int X0, Y0, X1, Y1;
void init(){
    gluOrtho2D(0,200,0,200);
}

void maindisplay(){

    glClearColor(0,0,0,0); // RGB-A Specify the color. Won't Change the color
    glClear(GL_COLOR_BUFFER_BIT); // Removes the color from COLOR_BUFFER_BIT after removing everything it'll fill the buffer with specified color
    glPointSize(5);
    //midpointLine(2,2,50,50);
    midpointLine();
    glFlush(); //Each one is rendered in a proper manner. (Here.. Finishes the job of the above functions)
}

void putpixel(int x, int y){
        // glColor3f(r,g,b) Specifying color to any object
    glColor3f(0.0,0.0,1.0);
    glPointSize(5);
    glBegin(GL_POINTS); // Draw Lines. Only 2 verteices.

        glVertex2f(x,y);

    glEnd();

}
//void midpointLine(int X0, int Y0, int X1, int Y1){
void midpointLine(){
    int dx = X1-X0;
    int dy = Y1-Y0;
    int d = (2*dy) - dx;
    int dE = 2*dy;
    int dNE = 2*(dy - dx);
    int x = X0;
    int y = Y0;
    putpixel(x,y);
    while(x<X1){
        if (d <= 0)
            d += dE;
        else {
            d += dNE;
            y++;
        }
        x++;
        putpixel(x,y);
    }

}


int main(int argc,char *argv[]){

    printf("Enter X0 Y0 X1 Y1 : ");
    scanf("%d%d%d%d", &X0,&Y0,&X1,&Y1);
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
