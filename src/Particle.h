#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector2D.h"


class Particle
{
public:
    // Constructor
	Particle(Vector2D pos, Vector2D vel)
	: position(pos),
	  velocity(vel)
    {}

    // Default constructor
    Particle() {};

    // Destructor
    virtual ~Particle() {};
	
    // Sets velocity
	void SetVelocity(Vector2D vec) {velocity = vec;}

    // Sets position
	void SetPosition(Vector2D vec) {position = vec;}

    // Gets position
	Vector2D GetPosition() const {return this->position;}

    // Gets velocity
	Vector2D GetVelocity() const {return this->velocity;}
	
	// Computes the squared distance from this particle to another
	float SquaredDistanceTo(const Particle &particle) const;
	
	// Computes the distance from this particle to another
	float DistanceTo(const Particle &particle) const;
	
	// Updates this particle
	void Update(float delta = 1.0);

protected:
	Vector2D position;
	Vector2D velocity;
};

#endif

