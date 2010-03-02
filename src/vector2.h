#pragma once
#include <math.h>
#include <vector>

using namespace std;

class Vector2
{
public:
	Vector2(float x = 0, float y = 0);
	virtual ~Vector2();
	
	Vector2 operator*(float scalar) const;
	Vector2 operator+(const Vector2 &vec) const;
	Vector2 operator-(const Vector2 &vec) const;
	
	float GetMagnitude();
	float GetX();
	float GetY();

	void Rotate(float angle);
	void Norm();
	
	float Cross(const Vector2 &vec) const;
	float Dot(const Vector2 &vec) const;
	
private:
	float _x, _y;
};
