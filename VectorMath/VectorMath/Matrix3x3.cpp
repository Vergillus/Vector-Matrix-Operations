#include "stdafx.h"
#include "Matrix3x3.h"

float Matrix3x3::Determinant()
{
	float resA , resB , resC;

	resA = this->data[0][0] * ((this->data[1][1] * this->data[2][2]) - (this->data[2][1] * this->data[1][2]));
	resB = this->data[0][1] * ((this->data[1][0] * this->data[2][2]) - (this->data[2][0] * this->data[1][2]));
	resC = this->data[0][2] * ((this->data[1][0] * this->data[2][1]) - (this->data[2][0] * this->data[1][1]));
	

	return resA - resB + resC;
}

Matrix3x3 Matrix3x3::Identity() 
{
	Matrix3x3 identity;

	for (int i = 0; i < identity.GetRow(); i++)
	{
		for (int j = 0; j < identity.GetColumn(); j++)
		{
			identity.data[i][j] = (i == j) ? 1.f : 0.f;
		}
	}

	return identity;
}

Matrix3x3 Matrix3x3::ZeroMatrix()
{
	Matrix3x3 zeroMatrix;

	for (int i = 0; i < zeroMatrix.GetRow(); i++)
	{
		for (int j = 0; j < zeroMatrix.GetColumn(); j++)
		{
			zeroMatrix.data[i][j] = 0.0f;
		}
	}

	return Matrix3x3();
}
