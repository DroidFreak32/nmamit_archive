#include <GL/glut.h>
#include <stdio.h>


void init()
{
      glClearColor(1.0, 1.0, 1.0, 1.0);
      glClear(GL_COLOR_BUFFER_BIT); 
      glMatrixMode(GL_PROJECTION);
      gluOrtho2D(0, 10, 0, 10);
}

void triangle(float *a,float *b, float *c)
{
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
     glVertex2f(a[0],a[1]);
     glVertex2f(b[0],b[1]);
     glVertex2f(c[0],c[1]);
    glEnd();
    glFlush();
}

void draw_triangle(float *a,float *b,float *c , int k)
{
	float ab[2],ac[2],bc[2];
	int i;
	if(k>0)
	{
	  for(i=0;i<2;i++){
		ab[i]=(a[i]+b[i])/2;
	  // for(i=0;i<2;i++)
		bc[i]=(b[i]+c[i])/2;
	  // for(i=0;i<2;i++)
		ac[i]=(a[i]+c[i])/2;
    }

	 draw_triangle(a,ab,ac,k-1);
	 draw_triangle(b,ab,bc,k-1);
	 draw_triangle(c,ac,bc,k-1);
	}
	else
	{
          triangle(a,b,c);
	}
}

void display()
{
    float a[2]={1,1};
    float b[2]={7,1};
    float c[2]={4,6};

    draw_triangle(a,b,c,2);
    
}
void myReshape(int w, int h)
{
   int ww = w;
    int hh = h;
    glViewport(0, 0, w, h);  
    glutPostRedisplay();
}
void main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500); 
    glutCreateWindow("Sierpinski Gasket"); 
    init();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display); 
    
    glutMainLoop(); 
}