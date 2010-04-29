#ifndef WELL_H
#define WELL_H


#include "Particle.h"
#include "Vector2D.h"
#include <time.h>
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

const float kWellSize = 3.0f;

class Well : public Particle
{
public:
    Well(Vector2D position, float mass, double lifespan):
      Particle(position, Vector2D(0,0), mass),
          lifespan(lifespan),
          start(NULL),
          end(NULL),
          size(kWellSize) 
      {
          time(&start);
      };

    Well() : Particle(Vector2D(0,0),Vector2D(0,0), 0), lifespan(0), start(NULL), end(NULL), size(kWellSize)
    {
        time(&start);
    };

    virtual ~Well() {};


    // See if this gravity well has expired
    // Returning true means the gravity well has not expired.
    bool CheckTime();

    void SetLifespan(double newLifespan) { lifespan = newLifespan; }

    void Draw();
private:

    // The lifespan, in seconds of this gravity well
    double lifespan;

    // Time objects to hold the time when this well was made active
    // and the time it may end.
    time_t start, end;
    
    float size;
};

#endif