#ifdef WIN32
    #include <windows.h>
#endif

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include "math.h"

#include "mass.h"

void Mass::Draw()
{
    glPointSize(this->radius);
    glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
        glVertex3f( this->GetPosition().X() - this->radius, this->GetPosition().Y() - this->radius, 0.0f);			// Top Left
		glVertex3f( this->GetPosition().X() - this->radius, this->GetPosition().Y() + this->radius, 0.0f);			// Top Right
        glVertex3f( this->GetPosition().X() + this->radius, this->GetPosition().Y() + this->radius, 0.0f);			// Bottom Right
        glVertex3f( this->GetPosition().X() + this->radius, this->GetPosition().Y() - this->radius, 0.0f);	        // Bottom left
    glEnd();
}

void Mass::ApplyGravityFrom(const Mass body, float timestep)
{
    float dx = this->position.X() - body.GetPosition().X(),
          dy = this->position.Y() - body.GetPosition().Y(),
          d  = DistanceTo(body);
    
    if(d < 20) d = 20.0f;
    
    /* Accel due to gravity = GM / d^2 = d / t^2
    We want change in velocity, which is d/t
    So multiply accel by t:
    GM / d^2 * t = GMt / d^2    unit: d/t
    But we want the components of that velocity
    So multiply by dx/d and dy/d:
       delta xv = GMt * dx / d^3
       delta yv = GMt * dy / d^3
    Calculate once GMt / d^3: */
    float hertz = body.GetMass() * timestep * -0.015 / (d*d*d);
    
    this->velocity = this->velocity + Vector2D(hertz*dx, hertz*dy);
}
