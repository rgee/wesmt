/* A 2D Vector Class */
#pragma once


class Vector2D
{
public:
	Vector2D(float x = 0, float y = 0)
	{
		this->_x = x;
		this->_y = y; 
	}
	
	virtual ~Vector2D(){ };
	
        /* C++ "trickery" point:
              Declaring const methods means a lot. I misspoke in the meeting.
              It tells the compiler which functions you can call on a const object or not.
         */
	float GetMagnitude() const;
	float x() const {return _x;}
	float y() const {return _y;}
	
	Vector2D operator*(float scalar) const { return Vector2D(this->_x * scalar, this->_y * scalar); }
	Vector2D operator+(const Vector2D &vec) const { return Vector2D(this->_x + vec.x(), this->_y + vec.y()); }
	Vector2D operator-(const Vector2D &vec) const { return Vector2D(this->_x - vec.x(), this->_y - vec.y()); }
	
	Vector2D& operator=(const Vector2D &rhs);
	

	void Rotate(float angle);
	void Norm();
	
	float Dot(const Vector2D &vec) const;
	
private:
	float _x, _y;
};
