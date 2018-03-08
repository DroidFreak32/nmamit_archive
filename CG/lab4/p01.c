#include <GL/glut.h>
#include <stdio.h>
int x0,y0,x1,y1;
void init(){
	//Mandatory so in init()

	glClearColor(1,1,1,0); // RGB-A Specify the color. Won't Change the color
    glClear(GL_COLOR_BUFFER_BIT); // Removes the color from COLOR_BUFFER_BIT after removing everything it'll fill the buffer with specified color

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /* In previous programs the window coordinates will be b/w -1 and 1
        But now using these lines we can specify our own window coordinates.
    */
    gluOrtho2D(0,500,0,500);
    glFlush(); //Each one is rendered in a proper manner. (Here.. Finishes the job of the above functions)
}

void plot(int x,int y) {
    glPointSize(4);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();

}

void display(){

    int d,dx,dy,x,y,incrE,incrNE;
    dx=x1-x0;
    dy=y1-y0;
    incrE=dy;
    incrNE=dy-dx;
    d=2*dy-dx;
    x=x0;
    y=y0;
    plot(x,y);
    while(x<x1){
        if(d<=0){
            d=d+2*incrE;
            x=x+1;
        }
        else{
            d=d+2*incrNE;
            x=x+1;
            y=y+1;
        }
        // system("sleep 1s");
        plot(x,y);
    }
    glFlush();
}

int main(int argc,char *argv[]){

    printf("\nEnter x0,y0,x1,y1\n");
    scanf("%d%d",&x0,&y0);
    scanf("%d%d",&x1,&y1);
    glutInit(&argc,argv);
    glutInitWindowSize(700,700);
    glutCreateWindow("Basic Window");
    glutInitWindowPosition(70,70);
    init();
    glutDisplayFunc(display); // Resize with and without the function see the diff
    // display();

     // glutDisplayFunc(display2); Here disp2 overlapps disp1 so disp1 cannot be seen


    glutMainLoop();
    return 0;
}
