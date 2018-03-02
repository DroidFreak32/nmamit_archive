#include <GL/glut.h>
#include <stdio.h>
#define top 8
#define bottom 4
#define right 2
#define left 1

#define true 1
#define false 0

float xmin=100, ymin=100, xmax=200, ymax=200, x0=50, y0=50, x1=250, y1=250;


void init(){
	glClearColor(1,1,1,1); // RGB-A Specify the color. Won't Change the color
    glClear(GL_COLOR_BUFFER_BIT); // Removes the color from COLOR_BUFFER_BIT after removing everything it'll fill the buffer with specified color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glFlush(); //Each one is rendered in a proper manner. (Here.. Finishes the job of the above functions)
}

int computeCode(int x, int y){
	int code=0;
	if (y>ymax)
		code = code|top;
	if (y<ymin)
		code = code|bottom;
	if (x>xmax)
		code = code|right;
	if (x<xmin)
		code = code|left;
	return code;
}

void drawRect(int trans){
        // glColor3f(r,g,b) Specifying color to any object
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP); // Draw Lines. Only 2 verteices.
        glVertex2f(xmin+trans,ymin+trans);
        glVertex2f(xmax+trans,ymin+trans);
        glVertex2f(xmax+trans,ymax+trans);
        glVertex2f(xmin+trans,ymax+trans);
    glEnd();
}

void drawLine(int trans){
        // glColor3f(r,g,b) Specifying color to any object
	glLineWidth(3);
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_LINES); // Draw Lines. Only 2 verteices.
        glVertex2f(x0+trans,y0+trans);
        glVertex2f(x1+trans,y1+trans);
    glEnd();
}
void cohenClip(){
    
    int oc0,oc1,ocout,accept=false,done=false;
    float x,y;
    oc0 = computeCode(x0,y0);
    oc1 = computeCode(x1,y1);

    do{
    	if ((oc0|oc1)==0) {
    		accept = true;
    		done = true;
    	}
    	else if ((oc0&oc1)!=0) {
    		accept = false;
    		done = true;
    	}
    	else{
    		ocout = (oc0) ? oc0 : oc1;
    		// if (oc0)
    		// 	ocout = oc0;
    		// else
    		// 	ocout = oc1;

    		if (ocout&top){
    			y=ymax;
    			x= x0+((x1-x0)*(ymax-y0))/(y1-y0);
    		}
    		else if (ocout&bottom){
    			y=ymin;
    			x= x0+((x1-x0)*(ymin-y0))/(y1-y0);
    		}
    		else if (ocout&right){
    			x=xmax;
    			y= y0+((y1-y0)*(xmax-x0))/(x1-x0);
    		}
    		else{
    			x=xmin;
    			y= y0+((y1-y0)*(xmin-x0))/(x1-x0);
    		}

    		if (ocout == oc0){
    			x0=x;
    			y0=y;
    			oc0 = computeCode(x0,y0);
    		}
    		else{
    			x1 = x;
    			y1 = y;
    			oc1 = computeCode(x1,y1);
    		}
    	}
    } while (done != true);

    if (accept == true){
    	drawRect(200);
    	drawLine(200);
    }

}

void display(){
	drawRect(0);
	drawLine(0);
	cohenClip();
	glFlush();
}


int main(int argc,char *argv[]){

    glutInit(&argc,argv);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Basic Window");
    init();
    glutDisplayFunc(display); // Resize with and without the function see the diff
    // display();

     // glutDisplayFunc(display2); Here disp2 overlapps disp1 so disp1 cannot be seen
    glutMainLoop();
    return 0;
}
