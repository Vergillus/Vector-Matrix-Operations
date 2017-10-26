// VectorMath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector2D.h"
#include "Matrix.h"
#include "Matrix3x3.h"
#include <iostream>


int main()
{
	Vector2D myVec(1.0f,2.0f);	
	Vector2D myVec2(1.0f, 2.0f);
	
	Vector2D myVec3 = myVec2 + myVec;

	Vector2D myVec4 =  myVec + 10.0f;

	std::cout << "x: " << myVec.x << " y: " << myVec3.y << "\n";

	Vector2D myVec5 = myVec - myVec2;

	float lol = myVec3.x + myVec3.y;
	float mag = myVec.SquaredMagnitude();
	float dot = myVec * myVec2;

	Vector2D v1{ 3.0,4.0 };
	Vector2D v2{ 4.0,3.0 };

	Vector2D v3{ 2.0,-1.0 };
	Vector2D v4{ -2.0,2.0 };

	Vector2D v5{ 1.0,2.0 };
	Vector2D v6{ 3.0,4.0 };

	Vector2D proj = Vector2D::ProjectVector(v5, v6);

	float distance = Vector2D::Distance(v4, v3);

	float angle = Vector2D::AngleBetweenTwoVectorsInDegrees(v1, v2);
	Vector2D myVec6 = myVec.Normalize();

	std::cout << "x: " << myVec3.x << " y: " << myVec3.y << "\n";
	std::cout << "x: " << myVec4.x << " y: " << myVec4.y << "\n";
	std::cout << "x: " << myVec5.x << " y: " << myVec5.y << "\n";
	std::cout << "x: " << myVec6.x << " y: " << myVec6.y << "\n";
	std::cout << " " << myVec6 << "\n";
	std::cout << "Mag: " << mag << "\n";
	//std::cout << myVec3.ToString() << "\n";

	std::cout <<"Angle:" << angle << "\n";
	std::cout << "distance:" << distance << "\n";
	std::cout << "Projection:" << proj << "\n";
	
	if (myVec == v6)
	{
		std::cout << "YES" << "\n";
	}
	else
	{
		std::cout << "NO" << "\n";
	}


	v6 *= 100.f;
	std::cout << v6 << "\n";

	Matrix m(3, 2);
	m.data[0][0] = 0.f;
	m.data[0][1] = 4.f;
	m.data[1][0] = 7.f;
	m.data[1][1] = 0.f;
	m.data[2][0] = 3.f;
	m.data[2][1] = 1.f;

	Matrix n(3, 2);
	n.data[0][0] = 1.f;
	n.data[0][1] = 2.f;
	n.data[1][0] = 2.f;
	n.data[1][1] = 3.f;
	n.data[2][0] = 0.f;
	n.data[2][1] = 4.f;

	Matrix MxN = m.MultiByScalar(0.5f);

	
	for (int i = 0; i < m.GetRow(); i++)
	{
		for (int j = 0; j < m.GetColumn(); j++)
		{
			std::cout <<"[ " <<m.data[i][j] << " ]";
		}
		std::cout << "\n";
	}

//	Matrix v = m.Transpose();
	Matrix::Transpose(m);

	for (int i = 0; i < m.GetRow(); i++)
	{
		for (int j = 0; j < m.GetColumn(); j++)
		{
			std::cout << "[ " << m.data[i][j] << " ]";
		}
		std::cout << "\n";
	}	

	std::cout << " Matrix Addition"<<"\n";
	for (int i = 0; i < MxN.GetRow(); i++)
	{
		for (int j = 0; j < MxN.GetColumn(); j++)
		{
			std::cout << "[ " << MxN.data[i][j] << " ]";
		}
		std::cout << "\n";
	}

	Matrix z(2, 2);
	z.data[0][0] = 1.f;
	z.data[0][1] = 6.f;
	z.data[1][0] = 9.f;
	z.data[1][1] = 3.f;
	
	Matrix x(2, 2);
	x.data[0][0] = 0.f;
	x.data[0][1] = -1.f;
	x.data[1][0] = -1.f;
	x.data[1][1] = 2.f;

	Matrix ZxX = z.MultiByMatrix(m);

	std::cout << " Matrix Multiplication" << "\n";
	for (int i = 0; i < ZxX.GetRow(); i++)
	{
		for (int j = 0; j < ZxX.GetColumn(); j++)
		{
			std::cout << "[ " << ZxX.data[i][j] << " ]";
		}
		std::cout << "\n";
	}


	Matrix identity = Matrix::Identity(5, 5);

	std::cout << " Identity Matrix" << "\n";
	for (int i = 0; i < identity.GetRow(); i++)
	{
		for (int j = 0; j < identity.GetColumn(); j++)
		{
			std::cout << "[ " << identity.data[i][j] << " ]";
		}
		std::cout << "\n";
	}

	/*Matrix M(3, 3);
	M.data[0][0] = 6.f;
	M.data[0][1] = 1.f;
	M.data[0][2] = 1.f;
	M.data[1][0] = 4.f;
	M.data[1][1] = -2.f;
	M.data[1][2] = 5.f;
	M.data[2][0] = 2.f;
	M.data[2][1] = 8.f;
	M.data[2][2] = 7.f;

	Matrix subM = Matrix::SubMatrix(1, 1, M);

	for (int i = 0; i < subM.GetRow(); i++)
	{
		for (int j = 0; j < subM.GetColumn(); j++)
		{
			std::cout << "[ " << subM.data[i][j] << " ]";
		}
		std::cout << "\n";
	}*/

	Matrix3x3 m3x3;
	m3x3.data[0][0] = 6.f;
	m3x3.data[0][1] = 1.f;
	m3x3.data[0][2] = 1.f;
	m3x3.data[1][0] = 4.f;
	m3x3.data[1][1] = -2.f;
	m3x3.data[1][2] = 5.f;
	m3x3.data[2][0] = 2.f;
	m3x3.data[2][1] = 8.f;
	m3x3.data[2][2] = 7.f;

	for (int i = 0; i < m3x3.GetRow(); i++)
	{
		for (int j = 0; j < m3x3.GetColumn(); j++)
		{
			std::cout << "[ " << m3x3.data[i][j] << " ]";
		}
		std::cout << "\n";
	}

	std::cout << "Determinant: " << m3x3.Determinat() << "\n";

	std::cin.get();

    return 0;
}

