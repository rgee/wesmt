#include "Vector2D.h"


class Particle
{
public:
	Particle(Vector2D pos, Vector2D vel)
	: position(pos),
	  velocity(vel)
	{}
	
	void SetVelocity(Vector2D vec) {this->velocity = vec;}
	void SetPosition(Vector2D vec) {this->position = vec;}
	Vector2D GetPosition() const {return this->position;}
	Vector2D GetVelocity() const {return this->velocity;}
	
	// Computes the squared distance from this particle to another
	float SquaredDistanceTo(const Particle &particle) const;
	
	// Computes the distance from this particle to another
	float DistanceTo(const Particle &particle) const;
	
	// Updates this particle
	void Update(float delta = 1.0);
private:
	Vector2D position;
	Vector2D velocity;
};
