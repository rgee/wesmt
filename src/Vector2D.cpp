#include "Vector2D.h"



inline Vector2D operator*(float scalar, const Vector2D &vec)
{
    return Vector2D(vec.data[0] * scalar, vec.data[1] * scalar);
}
Vector2D operator*(const Vector2D &vec, float scalar)
{
    return Vector2D(vec.data[0] * scalar, vec.data[1] * scalar);
}
inline Vector2D operator/(const Vector2D &vec, float scalar)
{
    return Vector2D(vec.data[0] / scalar, vec.data[1] / scalar);
}
inline Vector2D operator+(const Vector2D &v1, const Vector2D &v2)
{
    return Vector2D(v1.data[0] + v2.data[0], v1.data[1] + v2.data[1]);
}
inline Vector2D operator-(const Vector2D &v1, const Vector2D &v2)
{
    return Vector2D(v1.data[0] - v2.data[1], v1.data[0] - v2.data[1]);
}



Vector2D& Vector2D::operator+=(const Vector2D &v2)
{
    *this = *this + v2;
    return *this;
}
inline Vector2D& Vector2D::operator-=(const Vector2D &v2)
{
    *this = *this - v2;
    return *this;
}
inline Vector2D& Vector2D::operator*=(float s)
{
    *this = *this * s;
    return *this;
}
inline Vector2D& Vector2D::operator/=(float s)
{
    *this = *this / s;
    return *this;
}

/* Returns the magnitude of this vector */
inline float Vector2D::GetMagnitude() const
{
	return sqrt(data[0] * data[0] + data[1] * data[1]);
}

/* Rotates the vector some degrees clockwise if angle > 0
 * and counter-clockwise if angle < 0 */
void Vector2D::Rotate(const float angle)
{
	float xt = (data[0] * cos(angle)) - (data[1] * sin(angle));
	float yt = (data[1] * cos(angle)) + (data[0] * sin(angle));
	
	data[0] = xt;
	data[1] = yt;
}

/* Calculate the dot product between this vector and the arg */
float Vector2D::Dot(const Vector2D &vec) const
{
    return (data[0] * vec.data[0]) + (data[1] * vec.data[1]);
}



/* Assignment operator */
Vector2D& Vector2D::operator=(const Vector2D& v2)
{
	if (this != &v2)
    {
        data[0] = v2.data[0];
        data[1] = v2.data[1];
    }
	return *this;
}

