#include <GL/glut.h>
void init();
int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(400,200);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Basic Window");
    init();
    glutMainLoop();
    return 0;
}
void init(){
    glClearColor(1,1.0,1.0,0.0); // RGB-A Specify the color. Won't Change the color
    glClear(GL_COLOR_BUFFER_BIT); // Removes the color from COLOR_BUFFER_BIT after removing everything it'll fill the buffer with specified color
    glFlush(); //Each one is rendered in a proper manner. (Here.. Finishes the job of the above functions)    
}

