#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


void init(void);
void reshape(int width,int height);
void display(void);


void triangles(void);
void quads(void);

void exitAndClean();

void keyboard(unsigned char key,int x, int y);
void keySpecial (int key, int x, int y);

GLfloat quadtraslateX;
GLfloat quadtraslateY;


void TraslateX(float value);
void TraslateY(float value);


int main(int argc,char *argv[])
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);

    glutCreateWindow("animation and keyboard");

    init();
    //glutFullScreen();
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);


    glutKeyboardFunc(keyboard);//Teclado
    glutSpecialFunc(keySpecial); //Teclas especiales (Flechas)

    glutMainLoop();

    return 0;
}


void exitAndClean()
{
    exit(0);
}



void init(void)
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
}


//http://www.swiftless.com/tutorials/opengl/keyboard.html
void keyboard(unsigned char key,int x, int y)
{
    switch(key)
    {
    case 27: //Tecla de escape
        exitAndClean();
        break;
    case GLUT_KEY_UP:
        TraslateY(0.1);
        printf("Arriba\n");
        break;
    case GLUT_KEY_DOWN:
        TraslateY(-0.1);
        printf("Abajo\n");
        break;
    case 'b':
        glPolygonMode(GL_FRONT,GL_LINE);
        glPolygonMode(GL_BACK,GL_LINE);
        printf("Modo de poligono de linea\n");
        break;
    case 'v':
        glPolygonMode(GL_FRONT,GL_FILL);
        glPolygonMode(GL_BACK,GL_FILL);
        printf("Modo de poligono de relleno");
        break;
    }
}

//http://www.swiftless.com/tutorials/opengl/keyboard.html
void keySpecial (int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        TraslateY(0.1);
        printf("Arriba\n");
        break;
    case GLUT_KEY_DOWN:
        TraslateY(-0.1);
        printf("Abajo\n");
        break;
    case GLUT_KEY_RIGHT:
        TraslateX(0.1);
        printf("Derecha\n");
        break;
    case GLUT_KEY_LEFT:
        TraslateX(-0.1);
        printf("Izquierda\n");
        break;
    }
}

void reshape(int width,int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0,10.0,-10.0,10.0,-1.0,1.0); //Lienzo de -10 a 10 en X y Y
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(quadtraslateX,quadtraslateY,0.0);
    quads();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
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




void TraslateX(float value)
{
    quadtraslateX+=value;
}

void TraslateY(float value)
{
    quadtraslateY+=value;
}





