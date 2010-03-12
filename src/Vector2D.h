/* A 2D Vector Class */
#ifndef VECTOR2D_H
#define VECTOR2D_H
#include "math.h"
#include <iostream>


class Vector2D
{
public:
	// Constructor
	Vector2D(float X, float Y) 
	: x(X),
	  y(Y)
    {}

    Vector2D() : x(0), y(0) {};
	
	// Destructor
	virtual ~Vector2D(){ };
	
	// Gets the magnitude of this 2D vector
	float GetMagnitude() const;
	
	// Gets the X component of this 2D vector
	float X() const {return x;}
	
	// Gets the Y component of this 2D vector
	float Y() const {return y;}
	
	// Multiplies this vector by a scalar (float)
	Vector2D operator*(float scalar) const { return Vector2D(this->x * scalar, this->y * scalar); }
	
	// Adds this vector to another 2D vector
	Vector2D operator+(const Vector2D &vec) const { return Vector2D(this->x + vec.X(), this->y + vec.Y()); }
	
	// Subtracts a 2D vector from this 2D vector
	Vector2D operator-(const Vector2D &vec) const { return Vector2D(this->x - vec.Y(), this->y - vec.Y()); }
	
	// Assigns another vector to this 2D vector
	Vector2D& operator=(const Vector2D &rhs);

	// Rotates this vector clockwise by a float angle
	// If angle is negative, rotates counter-clockwise
	void Rotate(float angle);
	
	// Normalizes this vector
	void Norm();
	
	// Computes the dot product of this vector and another
	float Dot(const Vector2D &vec) const;
	
	// Computes the squared distance of two vectors
	static float SquaredDistance(const Vector2D &vec1, const Vector2D &vec2)
	{
		return pow((vec1.X() - vec2.X()), 2) +
			pow((vec1.Y() - vec2.Y()), 2);
	}
	
	// Computes the distance of two vectors
	static float Distance(const Vector2D &vec1, const Vector2D &vec2)
	{
		return sqrt(Vector2D::SquaredDistance(vec1, vec2));
	};
	
private:
	float x, y;
};
#endif