#ifndef WELL_H
#define WELL_H

class Vector2D;
class Mass;

class Well : public Particle
{
public:
    Well(Vector2D position, float mass): Particle(position, Vector2D(0,0)), mass(mass) {};
    Well() : Particle(Vector2D(0,0),Vector2D(0,0)), mass(0), isActive(false) {};

    virtual ~Well() {};

    float GetMass() const {return mass;}
    float SetMass(float newMass) {mass = newMass;}
private:
    Vector2D position;
    float mass;
    bool isActive;
};

#endif