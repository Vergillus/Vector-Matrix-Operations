#pragma once

#include <vector>
#include <assert.h>
#include <cmath>

class Matrix {

	int col, row;

public:	

	std::vector<std::vector<float>> data;
	//Matrix() {};
	Matrix(int rows, int colums) : row(rows), col(colums), data(row,std::vector<float>(col)) {};

	int GetColumn() const;
	int GetRow() const;

	Matrix Transpose();	

	static Matrix& Transpose(Matrix& inMatrix);	
	static Matrix Identity(const int row, const int col);
	//static Matrix SubMatrix(const int &startRow, const int &startCol, const Matrix& sourceMatrix);
	static Matrix SubMatrix(const Matrix& sourceMatrix, const int &startRow, const int &startCol, const int &endRow, const int &endCol);

	Matrix Add(const Matrix& inMatrix) const;
	Matrix Subtract(const Matrix& inMatrix) const;
	Matrix MultiByScalar(const float &val);
	Matrix MultiByMatrix(const Matrix &inMatrix) const;

	Matrix operator+(const Matrix &inMatrix) const;
	Matrix operator-(const Matrix &inMatrix) const;
	
	virtual float Determinant() { return 0.0f; };


private:

	

};
