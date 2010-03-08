#include "math.h"
#include "Particle.h"


class Mass : public Particle
{
public:
		void ApplyGravityFrom(const Mass mass);
private:
		float mass;
		float radius;
};
