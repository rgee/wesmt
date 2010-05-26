/* A 2D Vector Class */
#ifndef VECTOR2D_H
#define VECTOR2D_H
#include "math.h"
#include <iostream>


class Vector2D
{
public:
	// Constructor
	Vector2D(float X, float Y) { data[0] = X; data[1] = Y;}

    Vector2D() { data[0] = 0; data[1] = 0; };

    Vector2D(const Vector2D &v) { *this = v; }
	
	// Destructor
	virtual ~Vector2D(){ };
	
	// Gets the magnitude of this 2D vector
	inline float GetMagnitude() const;
	
	float X() const { return data[0]; }
	float Y() const { return data[1]; }
	/*-
	// Multiplies this vector by a scalar (float)
	inline const Vector2D operator*(float scalar) const { return Vector2D(data[0] * scalar, data[1] * scalar); }
	
	// Adds this vector to another 2D vector
	inline const Vector2D operator+(const Vector2D &vec) const { return Vector2D(data[0] + vec.data[0], this->y + vec.Y()); }
	
	// Subtracts a 2D vector from this 2D vector
	inline const Vector2D operator-(const Vector2D &vec) const { return Vector2D(this->x - vec.Y(), this->y - vec.Y()); 
    */

    friend Vector2D operator/(const Vector2D &vec, const float scalar);
    friend Vector2D operator*(const Vector2D &vec, float scalar);
    friend Vector2D operator*(float scalar, const Vector2D &vec);
    friend Vector2D operator+(const Vector2D &v1, const Vector2D &v2);
    friend Vector2D operator-(const Vector2D &v1, const Vector2D &v2);

    inline const Vector2D operator-() const { return Vector2D(-data[0], -data[1]); }
    
    Vector2D& operator+=(const Vector2D& v2);
    Vector2D& operator-=(const Vector2D& v2);
    Vector2D& operator*=(const float s);
    Vector2D& operator/=(const float s);
	Vector2D& operator=(const Vector2D &v2);


    inline void Normalize() { *this = *this / (*this).GetMagnitude(); }

	// Rotates this vector clockwise by a float angle
	// If angle is negative, rotates counter-clockwise
	void Rotate(const float angle);
	
	// Computes the dot product of this vector and another
	float Dot(const Vector2D &vec) const;
	
	// Computes the squared distance of two vectors
	inline static float SquaredDistance(const Vector2D &vec1, const Vector2D &vec2)
	{
        float x1 = vec1.data[0], x2 = vec2.data[0], y1 = vec1.data[1], y2 = vec2.data[1];

        return((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        /*
		return ( (vec1.X() - vec2.X()) * (vec1.X() - vec2.X()) ) +
			((vec1.Y() - vec2.Y()) * (vec1.Y() - vec2.Y()));
        */
	}
	
	// Computes the distance of two vectors
	static float Distance(const Vector2D &vec1, const Vector2D &vec2)
	{
		return sqrt(Vector2D::SquaredDistance(vec1, vec2));
	};
	
private:
	float data[2];
};
#endif

