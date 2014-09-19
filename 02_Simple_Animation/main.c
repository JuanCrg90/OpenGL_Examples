#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


void init(void);
void reshape(int width,int height);
void display(void);
void idle(void);

void triangles(void);
void quads(void);

GLfloat quadtraslate;
GLfloat triangletraslate;

int main(int argc,char *argv[])
{
    quadtraslate=1.0;
    triangletraslate=-1.0;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);

    glutCreateWindow("animation");

    init();
    //glutFullScreen();
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutIdleFunc(idle); //Aqui aplicaremos las actualizaciones de estado

    glutMainLoop();

    return 0;
}

void init(void)
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
}

void reshape(int width,int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(0.0,10.0,0.0,10.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    //https://www.opengl.org/sdk/docs/man2/xhtml/glPushMatrix.xml
    glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glTranslatef(triangletraslate,-1.0,0.0);
        triangles();

        glLoadIdentity();

        glScalef(0.5,0.5,0.5);
        glTranslatef(quadtraslate,1.0,0.0);
        glBegin(GL_QUADS);
        quads();
    glEnd();
    //https://www.opengl.org/sdk/docs/man2/xhtml/glPushMatrix.xml
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void idle(void)
{

    triangletraslate+=0.01;
    quadtraslate-=0.01;

    if(triangletraslate>1.0 && quadtraslate<-1.0)
    {
        triangletraslate= -1.0f;
        quadtraslate= 1.0f;
    }
    glutPostRedisplay();

}
void triangles(void)
{
    glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(-1.0f,-1.0f, 0.0f);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f( 1.0f,-1.0f, 0.0f);
    glEnd();
    glEnd();

}

void quads(void)
{
    glBegin(GL_QUADS);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glColor3f(0.0,1.0,0.0);
        glVertex3f( 1.0f, 1.0f, 0.0f);
        glColor3f(0.0,0.0,1.0);
        glVertex3f( 1.0f,-1.0f, 0.0f);
        glColor3f(1.0,0.0,1.0);
        glVertex3f(-1.0f,-1.0f, 0.0f);
    glEnd();

}

