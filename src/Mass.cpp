#ifdef WIN32
    #include <windows.h>
#endif
#include "math.h"
#include "GL/gl.h"

#include "mass.h"

void Mass::Draw()
{
    glPointSize(this->radius);
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_POINTS);
        glVertex3f(this->position.X(), this->position.Y(), -6.0f);
        glRotatef(45.0f, this->position.X(), this->position.Y(), -6.0f);
        glVertex3f(this->position.X(), this->position.Y(), -6.0f);
    glEnd();
}