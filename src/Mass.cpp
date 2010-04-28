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
    GLfloat square[] = { this->position.X() - this->size, this->position.Y() - this->size, 0.0f, /* Top left */
                           this->position.X() - this->size, this->position.Y() + this->size, 0.0f, /* Bottom left */
                           this->position.X() + this->size, this->position.Y() + this->size, 0.0f, /* Bottom right */
                           this->position.X() + this->size, this->position.Y() - this->size, 0.0f }; /* Top right */
    GLubyte indices[] = {0, 1, 2,
                         3, 1, 2};

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, square);
    glDrawElements(GL_QUADS, 6, GL_UNSIGNED_BYTE, indices);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

}

void Mass::ApplyGravityFrom(const Mass& body, float timestep)
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
