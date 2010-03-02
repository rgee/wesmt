#include "vector2.h"
#include <math.h>

using namespace std;


/* Returns the magnitude of this vector */
float Vector2D::GetMagnitude() const
{
	return sqrt((this->_x * this->_x) + (_y * _y));
}

/* Rotates the vector some degrees clockwise if angle > 0
 * and counter-clockwise if angle < 0 */
void Vector2D::Rotate(float angle)
{
	float xt = (_x * cos(angle)) - (_y * sin(angle));
	float yt = (_y * cos(angle)) + (_x * sin(angle));
	
	_x = xt;
	_y = yt;
}

/* Calculate the dot product between this vector and the arg */
float Vector2D::Dot(const Vector2D &vec) const
{
	return (_x * vec.x()) + (_y * vec.y());
}

/* Normalize the vector.
 * That is, turn it into a unit vector in the same direction
 * but of length zero. */
void Vector2D::Norm()
{
	float mag = this->GetMagnitude();
	this->_x = this->_x / mag;
	this->_y = this->_y / mag;
}

/* Assignment operator */
Vector2D& Vector2D::operator=(const Vector2D& rhs)
{
	if (&rhs == this) return *this;
	
	_x = rhs.x();
	_y = rhs.y();
	
	return *this;
}
