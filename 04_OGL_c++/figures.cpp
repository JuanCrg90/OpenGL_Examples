#include "figures.h"

Figures::Figures()
{
}


void Figures::triangles()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.0f,1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(-1.0f,-1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(1.0f,-1.0f);
    glEnd();
}
