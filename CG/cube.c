#include<GL/glut.h>
float q[8][3]={
	{-1,-1,-1},//0
    {1,-1,-1},//1
    {1,1,-1}, //2
    {-1,1,-1},//3
    {-1,-1,1},//4
    {1,-1,1}, //5
    {1,1,1}, //6
    {-1,1,1}
}; //7

float pos=0;
int theta[3]={0,0,0};
int axis=2;float angle=0;

void init(int w,int h) {
	float aspect=(float) w/h;
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w>=h)
	    glOrtho(-2.0*aspect,2.0*aspect,-2.0,2.0,2.0,-2.0);
	else
	    glOrtho(-2.0,2.0,-2.0/aspect,2.0/aspect,2.0,-2.0);
	glMatrixMode(GL_MODELVIEW);
	glutSwapBuffers();
}
void polygon(int a,int b,int c,int d){
	glBegin(GL_POLYGON);
	    glColor3f(1.0,0.0,0.0);
	    glVertex3fv(q[a]);
	    glColor3f(1.0,1.0,0.0);
	    glVertex3fv(q[b]);
	    glColor3f(1.0,0.0,1.0);
	    glVertex3fv(q[c]);
	    glColor3f(0.0,1.0,1.0);
	    glVertex3fv(q[d]);
	glEnd();

}

void spinCube() {
	//Idle callback, spin cube 2 degrees about selected axis
	theta[axis] += 2.0;
	if( theta[axis] > 360.0 )
    	theta[axis] -= 360.0;
	glutPostRedisplay();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);

    polygon(0,3,2,1);//back
	polygon(2,3,7,6);//top
	polygon(0,4,7,3);//left
	polygon(1,2,6,5);//right
	polygon(4,5,6,7);//front
	polygon(0,1,5,4);//bottom

	glPopMatrix();
	glutSwapBuffers();
}

void mykeyboard(unsigned char c,int x,int y) {
	if(c=='x'||c=='X')
		axis=0;
	if(c=='y'||c=='Y')
		axis=1;
	if(c=='z'||c=='Z')
		axis=2;
}

int main(int argc,char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE );
	glutInitWindowSize(500,500);
	glutCreateWindow("quads");
	glutReshapeFunc(init);
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutKeyboardFunc(mykeyboard);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
