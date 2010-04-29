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
    glColor3f(this->r, this->g, this->b);

    
    GLfloat vertices[722];
    float cnst = 3.1415927/360;
    for(int i = 0; i < 722; i+=2){
        vertices[i]   = this->position.X() + cos(cnst * i) * this->size;
        vertices[i+1] = this->position.Y() + sin(cnst * i) * this->size;
    }
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 361);

}

void Mass::ApplyGravityFrom(const Particle& body, float timestep)
{
    float dx = this->position.X() - body.GetPosition().X(),
          dy = this->position.Y() - body.GetPosition().Y(),
          d  = DistanceTo(body);
    
    if(d < 20)
        d = 8000.0f;
    else
        d = d * d * d;
    
    /* Accel due to gravity = GM / d^2 = d / t^2
    We want change in velocity, which is d/t
    So multiply accel by t:
    GM / d^2 * t = GMt / d^2    unit: d/t
    But we want the components of that velocity
    So multiply by dx/d and dy/d:
       delta xv = GMt * dx / d^3
       delta yv = GMt * dy / d^3
    Calculate once GMt / d^3 (d has been pre-cubed): */
    float hertz = body.GetMass() * timestep * -0.0015 / d;

    this->velocity = Vector2D(hertz*dx + this->velocity.X(),
                              hertz*dy + this->velocity.Y());
}
