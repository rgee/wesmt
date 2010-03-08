#include "Vector2D.h"


/* Returns the magnitude of this vector */
float Vector2D::GetMagnitude() const
{
	return sqrt((this->x * this->x) + (y * y));
}

/* Rotates the vector some degrees clockwise if angle > 0
 * and counter-clockwise if angle < 0 */
void Vector2D::Rotate(float angle)
{
	float xt = (x * cos(angle)) - (y * sin(angle));
	float yt = (y * cos(angle)) + (x * sin(angle));
	
	x = xt;
	y = yt;
}

/* Calculate the dot product between this vector and the arg */
float Vector2D::Dot(const Vector2D &vec) const
{
	return (x * vec.X()) + (y * vec.Y());
}

/* Normalize the vector.
 * That is, turn it into a unit vector in the same direction
 * but of length zero. */
void Vector2D::Norm()
{
	float mag = this->GetMagnitude();
	this->x = this->x / mag;
	this->y = this->y / mag;
}

/* Assignment operator */
Vector2D& Vector2D::operator=(const Vector2D& rhs)
{
	if (&rhs == this) return *this;
	
	x = rhs.X();
	y = rhs.Y();
	
	return *this;
}

