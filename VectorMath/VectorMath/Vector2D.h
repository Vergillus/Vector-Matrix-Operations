#pragma once
#include <iostream>
#include <string>

class Vector2D {

public:

	float x, y;

	Vector2D() : x(0), y(0) {};

	Vector2D(float valX, float valY) 
		: x(valX), y(valY) { }
	
	Vector2D Add(const Vector2D &inVal);
	Vector2D Subtract(const Vector2D &inVal);
	
	Vector2D operator+(const Vector2D &inVec);
	Vector2D operator+(float val) const;

	Vector2D operator-(const Vector2D &inVec) const;
	Vector2D operator-(float val) const;
	Vector2D operator-() const;
		
	Vector2D operator*(const float &val);
	
	Vector2D operator/(const float &val);
	Vector2D operator/(const Vector2D &inVec);

	bool operator==(const Vector2D &inVec) const;
	
	Vector2D& operator*=(const float &val);	

	float& operator[](int &index);
	float  operator[](int &index) const;

	Vector2D Normalize();
	static Vector2D ZeroVector();
	static Vector2D UnitVector();
	static Vector2D Negate(const Vector2D &inVec);

	/** Calculates and returns the euclidean distance between two vectors. 
	   Order of vector does not matter because of the magnitude operation.*/
	static float Distance(const Vector2D &v1, const Vector2D &v2);
	static float SquaredDistance(const Vector2D &v1, const Vector2D &v2);
	static float AngleBetweenTwoVectorsInRadians(Vector2D  &v1, Vector2D  &v2);
	static float AngleBetweenTwoVectorsInDegrees(Vector2D  &v1, Vector2D  &v2);
	static Vector2D ProjectVector(const Vector2D &v1, const Vector2D &v2);
	static Vector2D PerpendicularVector(const Vector2D &v1, const Vector2D &v2);
	static float DotProduct(const Vector2D &v1, const Vector2D &v2);
	/** Dot product of two vectors
		@If 0 < result < 90 then the two vector are pointing in the same direction
		@If result = 0 then the two vector are perpendicular to each other
		@If 90 < result < 180 then the two vector are pointing in the opposite directions
	*/
	float Dot(const Vector2D &inVal);
	float CrossProduct(const Vector2D  &inVec);

	float Magnitude() const;
	float SquaredMagnitude() const;
	
	float GetMax() const;
	float GetMin() const;

	float operator*(const Vector2D &inVec);
	std::string ToString();
	

private:



};
Vector2D operator+(const float & val, const Vector2D & inVec);
Vector2D operator*(const float &val, const Vector2D &inVec);
std::ostream &operator<<(std::ostream &output, const Vector2D &inVec);
