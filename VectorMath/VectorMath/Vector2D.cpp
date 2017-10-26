#include "stdafx.h"
#include "Vector2D.h"
#include <math.h>


#define PI 3.141593

Vector2D Vector2D::ZeroVector()
{
	return Vector2D(0.0f, 0.0f);	
}

Vector2D Vector2D::UnitVector()
{
	return Vector2D(1.0f,1.0f);
}

Vector2D Vector2D::Negate(const Vector2D &inVec)
{
	return Vector2D(-inVec.x,-inVec.y);
}

float Vector2D::Distance(const Vector2D & v1, const Vector2D & v2)
{
	return sqrt(SquaredDistance(v1,v2));
}

float Vector2D::SquaredDistance(const Vector2D & v1, const Vector2D & v2)
{
	return (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y);
}

Vector2D Vector2D::Add(const Vector2D &inVal)
{
	return Vector2D(x + inVal.x,y+inVal.y);
}

Vector2D Vector2D::Subtract(const Vector2D &inVal)
{
	return Vector2D(x - inVal.x, y - inVal.y);
}

float Vector2D::AngleBetweenTwoVectorsInRadians(Vector2D & v1, Vector2D & v2)
{
	float dot = v1 * v2;
	float magV1 = v1.Magnitude();
	float magV2 = v2.Magnitude();
	
	float cos = dot / (magV1 * magV2);

	return acos(cos);
}

float Vector2D::AngleBetweenTwoVectorsInDegrees(Vector2D & v1, Vector2D & v2)
{
	return AngleBetweenTwoVectorsInRadians(v1,v2) * (180.f / PI);
}

Vector2D Vector2D::ProjectVector(const Vector2D & v1, const Vector2D & v2)
{
	return  (Vector2D::DotProduct(v1, v2) / v2.SquaredMagnitude()) * v2;
}

Vector2D Vector2D::PerpendicularVector(const Vector2D & v1, const Vector2D & v2)
{
	return  (v2 - v1) * (Vector2D::DotProduct(v1, v2) / v2.SquaredMagnitude());
}

float Vector2D::DotProduct(const Vector2D & v1, const Vector2D & v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

float Vector2D::Dot(const Vector2D &inVal)
{	
	return (x * inVal.x) + (y * inVal.y);;
}

Vector2D Vector2D::operator+(const Vector2D &inVec)
{
	return Vector2D::Add(inVec);
}

Vector2D Vector2D::operator+(float val) const
{
	return Vector2D(x + val, y + val);
}

Vector2D Vector2D::operator-(const Vector2D &inVec) const
{
	return Vector2D(x - inVec.x, y - inVec.y);
}

Vector2D Vector2D::operator-(float val) const
{
	return Vector2D(x - val, y - val);
}

Vector2D Vector2D::operator-() const
{	
	return Vector2D(-x,-y);
}

Vector2D Vector2D::operator*(const float &val)
{
	return Vector2D(x * val, y * val);
}

float Vector2D::operator*(const Vector2D &inVec)
{
	return Vector2D::Dot(inVec);
}

std::string Vector2D::ToString()
{
	return std::string("X= " + std::to_string(x) + " Y= " + std::to_string(y));
}

Vector2D Vector2D::operator/(float const &val)
{
	const float scale = 1.f / val;
	return Vector2D(x * scale , y * scale);
}

Vector2D Vector2D::operator/(const Vector2D & inVec)
{
	return Vector2D(x / inVec.x, y / inVec.y);
}

bool Vector2D::operator==(const Vector2D & inVec) const
{
	return ((x == inVec.x) && (y == inVec.y)) ? true : false;
}

Vector2D & Vector2D::operator*=(const float & val) 
{
	x *= val;
	y *= val;

	return *this;	
}

float & Vector2D::operator[](int &index)
{
	if (index >= 0 && index<2)
	{
		return (index == 0) ? x : y;
	}	
}

float Vector2D::operator[](int &index) const
{
	if (index >= 0 && index<2)
	{
		return (index == 0) ? x : y;
	}
}

Vector2D Vector2D::Normalize()
{
	float VecMag = Magnitude();	
	if (VecMag != 0)
	{
		return Vector2D(x / VecMag, y / VecMag);
	}
	
}

float Vector2D::CrossProduct(const Vector2D &inVec)
{
	return (x * inVec.y - y * inVec.x);
}

float Vector2D::Magnitude() const
{
	return sqrt(x*x + y*y);
}

float Vector2D::SquaredMagnitude() const
{
	return x*x + y*y;
}

float Vector2D::GetMax() const
{
	return (x < y) ? y : x;
}

float Vector2D::GetMin() const
{
	return (x < y) ? x : y;
}

Vector2D operator+(const float &val, const Vector2D &inVec)
{
	return Vector2D(val + inVec.x, val + inVec.y);
}

Vector2D operator-(const float &val, const Vector2D &inVec)
{
	Vector2D tmp;
	tmp.y = val - inVec.y;
	tmp.x = val - inVec.x;

	return Vector2D(val - inVec.x, val - inVec.y);
}

Vector2D operator*(const float &val, const Vector2D &inVec)
{
	return Vector2D(val * inVec.x, val * inVec.y);
}

std::ostream & operator<<(std::ostream & output, const Vector2D & inVec)
{
	output << " X= " << inVec.x << " Y= " << inVec.y;
	return output;	
}

