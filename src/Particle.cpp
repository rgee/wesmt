#include "Particle.h"
#include "Vector2D.h"
#include <string>
#include "math.h"



float Particle::SquaredDistanceTo(const Particle &particle) const
{
	return Vector2D::SquaredDistance(this->position, particle.position);
}

float Particle::DistanceTo(const Particle &particle) const
{
	return sqrt(this->SquaredDistanceTo(particle));
}

void Particle::Update(float delta)
{
	this->position += (velocity * delta);
}



