// A Mass is a visible gravitational body. Inherits from Particle.

#ifndef MASS_H
#define MASS_H
#include "math.h"
#include "Vector2D.h"
#include "Particle.h"


class Mass : public Particle
{
public:

    // Constructor
    Mass(Vector2D position, Vector2D velocity, float mass, float radius) :
      Particle(position, velocity),
      mass(mass),
      radius(radius)
      {};

    // Default constructor
    Mass() : 
      Particle(Vector2D(0.0f,0.0f),Vector2D(0.0f,0.0f)),
      mass(0.0f),
      radius(1.0f)
      {};

    // Destructor
    virtual ~Mass(){};

    // Applies gravitational force from another gravitational
    // body.
    void ApplyGravityFrom(const Particle body);

    // Draws this mass to the screen
    void Draw();

    // Sets the mass
    void SetMass(float newMass) {mass = newMass;}

    // Sets the radius
    void SetRadius(float newRadius) {radius = newRadius;}

    // Gets the mass
    float GetMass() const { return mass;}

    // Gets the radius
    float GetRadius() const { return radius;}

private:
    // The mass value of this mass
    float mass;

    // The radius of this mass
	float radius;
};
#endif