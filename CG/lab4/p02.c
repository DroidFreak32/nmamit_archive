#include <GL/glut.h>
#include<math.h>
#include<string.h>
#include <stdio.h>
int r;
void init(){
	//Mandatory so in init()

	glClearColor(1,1,1,0); // RGB-A Specify the color. Won't Change the color
    glClear(GL_COLOR_BUFFER_BIT); // Removes the color from COLOR_BUFFER_BIT after removing everything it'll fill the buffer with specified color

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /* In previous programs the window coordinates will be b/w -1 and 1
        But now using these lines we can specify our own window coordinates.
    */
    gluOrtho2D(-500,500,-500,500);
    glFlush(); //Each one is rendered in a proper manner. (Here.. Finishes the job of the above functions)
}

void plot(int x,int y) {
	glPointSize(4);
    glBegin(GL_POINTS);
	    glColor3f(1.0,0.0,0.0);
	    glVertex2f(x,y);
	    glColor3f(1.0,1.0,0.0);
	    glVertex2f(x,-y);
	    glColor3f(1.0,0.0,1.0);
	    glVertex2f(-x,-y);
	    glColor3f(0.0,0.0,0.0);
	    glVertex2f(-x,y);
	    glColor3f(0.0,1.0,0.0);
	    glVertex2f(y,x);
	    glColor3f(0.0,0.0,1.0);
	    glVertex2f(y,-x);
	    glColor3f(0.0,1.0,1.0);
	    glVertex2f(-y,x);
	    glColor3f(1.0,0.5,1.0);
	    glVertex2f(-y,-x);
    glEnd();
}

void midpoint_circle(){
	int x=0;
	int y=r;
	int d=1.25-r;
    plot(x,y);
    while(y>x){
        if(d<0){
            d+=2*x+3;
        }
        else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
        plot(x,y);
    }
}
void display(){
	midpoint_circle();
    glFlush();
}

int main(int argc,char *argv[]){

    printf("\nEnter r\n");
    scanf("%d",&r);
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Basic Window");
    glutInitWindowPosition(70,70);
    init();
    glutDisplayFunc(display); // Resize with and without the function see the diff
    // display();

     // glutDisplayFunc(display2); Here disp2 overlapps disp1 so disp1 cannot be seen


    glutMainLoop();
    return 0;
}
