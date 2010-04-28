#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector2D.h"


class Particle
{
public:
    // Constructor
	Particle(Vector2D pos, Vector2D vel, float mass)
	: position(pos),
	  velocity(vel),
      mass(mass)
    {}

    // Default constructor
    Particle() {};

    // Destructor
    virtual ~Particle() {};
	
    // Sets velocity
	void SetVelocity(Vector2D vec) {velocity = vec;}

    // Sets position
	void SetPosition(Vector2D vec) {position = vec;}

    // Sets mass
    void SetMass(float newMass){this->mass = newMass;}

    // Gets position
	inline Vector2D GetPosition() const {return this->position;}

    // Gets velocity
	inline Vector2D GetVelocity() const {return this->velocity;}

    // Gets mass
    float GetMass() const {return this->mass;}
    
	// Computes the squared distance from this particle to another
	float SquaredDistanceTo(const Particle &particle) const;
	
	// Computes the distance from this particle to another
	float DistanceTo(const Particle &particle) const;
	
	// Updates this particle
	void Update(float delta = 1.0);

protected:
	Vector2D position;
	Vector2D velocity;
    float mass;
};

#endif

