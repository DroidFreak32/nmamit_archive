// Display point
#include <GL/glut.h>
void init();

void display1(){

	// glColor3f(r,g,b) Specifying color to any object
	glColor3f(1.0,0.0,0.0);

	glPointSize(9);
    glBegin(GL_POINTS); // Can specify N number of points

    	//Specify the points coordinates b/w -1 & 1
    	glVertex2f(0.0,0.0);
    	glVertex2f(0.0,-0.5);
    	glVertex2f(0.0,0.5);
    glEnd();
    glFlush();
    display2();
}

void display2(){

	// glColor3f(r,g,b) Specifying color to any object
	glColor3f(0.0,0.0,1.0);

	glPointSize(9);
    glBegin(GL_POINTS); // Can specify N number of points

    	//Specify the points coordinates b/w -1 & 1
    	glVertex2f(-0.25,0.0);
    	glVertex2f(-0.50,0.0);
    	glVertex2f(0.25,0.0);
    	glVertex2f(0.50,0.0);
    glEnd();
    glFlush();
}
int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(70,70);
    glutCreateWindow("Basic Window");
    init();
    glutDisplayFunc(display1); // Resize with and without the function see the diff
    // display();

     // glutDisplayFunc(display2); Here disp2 overlapps disp1 so disp1 cannot be seen


    glutMainLoop();
    return 0;
}


void init(){
    glClearColor(0.5,0.5,0.5,0.5); // RGB-A Specify the color. Won't Change the color
    glClear(GL_COLOR_BUFFER_BIT); // Removes the color from COLOR_BUFFER_BIT after removing everything it'll fill the buffer with specified color
    glFlush(); //Each one is rendered in a proper manner. (Here.. Finishes the job of the above functions)    
}

//glutDisplayFunc(display_func_name) mandatory to invoke any function