#include <stdio.h>
#include <GL/glut.h> //biblioteca para creación de las ventanas FREEGLUT
#include <GL/gl.h>  //biblioteca de primitivas de OpenGL

void init(void);
void reshape(int width,int height);
void display(void);

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);

    glutCreateWindow("Reshape");

    init();
    //glutFullScreen();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

void init(void)
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
}

void reshape(int width,int height)
{
    printf("%d %d\n",width,height);


    glViewport(0,0,width,height);

    //https://www.opengl.org/sdk/docs/man2/xhtml/glMatrixMode.xml
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    glOrtho(-10.0f,10.0f,-10.0f,10.0f,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glutPostRedisplay();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.0f,1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-1.0f,-1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(1.0f,-1.0f);
    glEnd();

    glFlush();
    glutPostRedisplay();

}

