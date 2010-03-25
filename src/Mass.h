// A Mass is a visible gravitational body. Inherits from Particle.

#ifndef MASS_H
#define MASS_H
#include "math.h"
#include "Vector2D.h"
#include "Particle.h"
#include "AABB.h"


class Mass : public Particle
{
public:

    // Constructor
    Mass(Vector2D position, Vector2D velocity, float mass, float radius) :
      Particle(position, velocity),
      bbDirty(false),
      mass(mass),
      radius(radius),
      boundingBox(position, radius),
      exists(false)
      {};

    // Default constructor
    Mass() : 
      Particle(Vector2D(0.0f,0.0f),Vector2D(0.0f,0.0f)),
      mass(0.0f),
      radius(1.0f),
      exists(false)
      { SetColor(255, 255, 255); }

    // Destructor
    virtual ~Mass(){};

    inline void SetExists(bool newExists) { exists = newExists;}
    inline bool GetExists() { return exists;}

    // Applies gravitational force from another gravitational
    // body.
    void ApplyGravityFrom(const Mass& body, float timestep);

    // Draws this mass to the screen
    void Draw();

    // Sets the mass
    void SetMass(float newMass) {mass = newMass;}

    // Sets the radius
    void SetRadius(float newRadius) {radius = newRadius;}

    // Gets the mass
    inline float GetMass() const { return mass;}

    // Gets the radius
    float GetRadius() const { return radius;}

    // Get the status of the AABB
    bool GetBBDirty() const { return bbDirty;}

    // Set the status of the AABB
    void SetBBDirty(bool dirty) { bbDirty = dirty;}

    // Set this mass' color
    void SetColor(GLubyte R, GLubyte G, GLubyte B) { r = R; g = G; b = B; }



private:
    // Flag to say whether the AABB needs to be recomputed or not.
    // Dirty = AABB is centered at a previous point and needs recomputing
    // Not Dirty = AABB is current.
    bool bbDirty;

    // The mass value of this mass
    float mass;

    // The radius of this mass
	float radius;

    // This mass's bounding box
    AABB boundingBox;

    // Does this particle actually exist on screen?
    bool exists;

    // Color values from 0-255
    GLubyte r, g, b;
};
#endif