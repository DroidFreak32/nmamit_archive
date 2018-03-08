/* 4 cases
both inside without intersection
both outside without intersection
one inside with intersection
current one
*/


#include<GL/glut.h>
#define BOTTOM 4
#define TOP 8
#define RIGHT 2
#define LEFT 1
#define true 1
#define false 0
float x0,y0,x1,y1,Xmin,Ymin,Xmax,Ymax;

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glFlush();
}
void draw_line(float x0,float y0,float x1,float y1)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(x0,y0);
    glVertex2f(x1,y1);
    glEnd();
}
void draw_rectangle(float Xmin,float Ymin,float Xmax,float Ymax)
{
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(Xmin,Ymin);
    glVertex2f(Xmin,Ymax);
    glVertex2f(Xmax,Ymax);
    glVertex2f(Xmax,Ymin);
    glEnd();
    glFlush();
}
int compute_code(float x,float y)
{
    int code=0;
    if(y>Ymax)
    {
        code=code|TOP;
    }
    if(y<Ymin)
    {
        code=code|BOTTOM;
    }
    if(x>Xmax)
    {
        code=code|RIGHT;
    }
    if(x<Xmin)
    {
        code=code|LEFT;
    }
    return code;
}
void cohen_sutherland()
{
    float x,y;
    int outcode0,outcode1,outcodeout;
    int accept = false;
    int done = false;
    outcode0 = compute_code(x0,y0);
    outcode1 = compute_code(x1,y1);
    do {
        if((outcode0|outcode1)==0)
        {
            accept=true;
            done=true;
        }
        else if((outcode0&outcode1)!=0)
        {
            accept=false;
            done=true;
        }
        else
        {

            outcodeout=outcode0?outcode0:outcode1;
            if(outcodeout&TOP)
            {
                y=Ymax;
                x=x0+((x1-x0)*(Ymax-y0))/(y1-y0);
            }
            else if(outcodeout&BOTTOM)
            {
                y=Ymin;
                x=x0+((x1-x0)*(Ymin-y0))/(y1-y0);
            }
            else if(outcodeout&RIGHT)
            {
                x=Xmax;
                y=y0+((y1-y0)*(Xmax-x0))/(x1-x0);
            }
            else
            {
                x=Xmin;
                y=y0+((y1-y0)*(Xmin-x0))/(x1-x0);
            }
            if(outcodeout==outcode0)
            {
                x0=x;
                y0=y;
                outcode0=compute_code(x0,y0);
            }
            else
            {
                x1=x;
                y1=y;
                outcode1=compute_code(x1,y1);
            }
        }
    } while(done==false);
    if(accept)
    {
        draw_rectangle(Xmin+200,Ymin+200,Xmax+200,Ymax+200);
        draw_line(x0+200,y0+200,x1+200,y1+200);
    }

}
void display()
{
    draw_rectangle(Xmin,Ymin,Xmax,Ymax);
    draw_line(x0,y0,x1,y1);
    cohen_sutherland();
    glFlush();
}
int main(int argc,char *argv[])
{
    x0=20;
    y0=20;
    x1=200;
    y1=200;
    Xmin=50;
    Ymin=50;
    Xmax=150;
    Ymax=150;
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("LINE");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
