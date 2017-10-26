#pragma once

#include "Matrix.h"

class Matrix3x3 : public Matrix 
{

public:

	Matrix3x3() : Matrix(3, 3) {};

	virtual float Determinant() override;

	static Matrix3x3 Identity();
	static Matrix3x3 ZeroMatrix();


};
