//Programa 00_Hello_World
//Autor Juan Carlos Ruiz

#include <stdio.h>
#include <GL/glut.h> //biblioteca para creación de las ventanas FREEGLUT
#include <GL/gl.h>  //biblioteca de primitivas de OpenGL


void display(); //función de pintado



int main(int argc, char *argv[])
{

    glutInit(&argc,argv);  //Inicializa la biblioteca


    //Inicializa las caracteristicas de pintado, aquí definimos si soporta animación si soporta 3D, el modo de color, ETC
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);

    //Posición inicial de la ventana
    glutInitWindowPosition(100,100);

    //Tamaño de la ventana
    glutInitWindowSize(512,512);

    //Título de la ventana
    glutCreateWindow("Hello OpenGL");

    //Pantalla completa
    //glutFullScreen();

    //Puntero a función de la función de pintado
    glutDisplayFunc(display);

    //Ciclo principal del programa
    glutMainLoop();


    return 0;
}

void display(void)
{
    //https://www.opengl.org/sdk/docs/man/html/glClearColor.xhtml
    glClearColor(0.0,0.0,0.0,0.0);


    //https://www.opengl.org/sdk/docs/man2/xhtml/glClear.xml
    glClear(GL_COLOR_BUFFER_BIT);

    //https://www.opengl.org/sdk/docs/man2/xhtml/glMatrixMode.xml
    glMatrixMode(GL_PROJECTION);

    //https://www.opengl.org/sdk/docs/man2/xhtml/glLoadIdentity.xml
    glLoadIdentity();



    //--------------------------------------------------------------//
    //NOTA:															//
    //GL_POINTS grafica una coleccion de puntos						//
    //GL_LINES toma los puntos en pares para dibujar lineas			//
    //GL_LINE_STRIP Lineas consecutivas								//
    //GL_LINE_LOOP lineas consecutivas en ciclo						//
    //GL_TRIANGLES triangulos entre 3 puntos						//
    //GL_TRIANGLE_STRIP triangulos consecutivos						//
    //GL_TRIANGLE_FAN												//
    //GL_QUADS			Cuadrilateros								//
    //GL_QUAD_STRIP 	Cuadrilateros consecutivos					//
    //GL_POLYGON		crea poligonos con los puntos dados			//
    //					Similar a LINE_LOOP							//
    //----------------------------------------------------------------

    glPointSize(5.0f);
    glBegin(GL_LINE_LOOP);
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
