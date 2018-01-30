#include <GL/glut.h>
void init();
int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(200,200);
    glutInitWindowPosition(70,70);
    glutCreateWindow("Basic Window");
    init();
    glutMainLoop();
    return 0;
}
void init(){
    glClearColor(0.5,0.0,0.0,0.0); // RGB-A Specify the color. Won't Change the color
    glClear(GL_COLOR_BUFFER_BIT); // Removes the color from COLOR_BUFFER_BIT after removing everything it'll fill the buffer with specified color
    glFlush(); //Each one is rendered in a proper manner. (Here.. Finishes the job of the above functions)    
}

