#include "stdafx.h"
#include "Matrix.h"

int Matrix::GetColumn() const
{
	return col;
}

int Matrix::GetRow() const
{
	return row;
}

Matrix Matrix::Transpose()
{
	Matrix tmp(col, row);

	for (int i = 0; i < tmp.GetRow(); i++)
	{
		for (int j = 0; j < tmp.GetColumn(); j++)
		{
			tmp.data[i][j] = this->data[j][i];
		}
	}

	return tmp;
}

Matrix & Matrix::Transpose(Matrix & inMatrix)
{
	inMatrix = inMatrix.Transpose();
	return inMatrix;
	// TODO: insert return statement here
}

Matrix Matrix::Identity(const int row, const int col) 
{
	Matrix tmp(row, col);	

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{	
			tmp.data[i][j] = (i == j) ? 1.f : 0.f;
		}
	}
	return tmp;
}

Matrix Matrix::SubMatrix(const Matrix & sourceMatrix, const int & startRow, const int & startCol, const int & endRow, const int & endCol)
{
	Matrix tmp(std::abs(startRow - endRow),std::abs(startCol - endCol));
	
		for (int i = 0; i < endRow; i++)
		{
			for (int j = 0; j < endCol; j++)
			{
				tmp.data[i][j] = sourceMatrix.data[i + startRow][j + startCol];
			}
		}
	
		return tmp;
}

//Matrix Matrix::SubMatrix(const int & startRow, const int & startCol, const Matrix & sourceMatrix)
//{
//	Matrix tmp(sourceMatrix.GetRow() - 1, sourceMatrix.GetColumn() - 1);
//
//	for (int i = 0; i < startRow + 1; i++)
//	{
//		for (int j = 0; j < startCol + 1; j++)
//		{
//			tmp.data[i][j] = sourceMatrix.data[i + startRow][j + startCol];
//		}
//	}
//
//	return tmp;
//}

Matrix Matrix::Add(const Matrix & inMatrix) const
{
	assert(inMatrix.GetRow() == row && inMatrix.GetColumn() == col);
	Matrix tmp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			tmp.data[i][j] = this->data[i][j] + inMatrix.data[i][j];
		}
	}
	return tmp;
}

Matrix Matrix::Subtract(const Matrix & inMatrix) const
{
	assert(inMatrix.GetRow() == row && inMatrix.GetColumn() == col);
	Matrix tmp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			tmp.data[i][j] = this->data[i][j] - inMatrix.data[i][j];
		}
	}
	return tmp;
}

Matrix Matrix::MultiByScalar(const float & val)
{
	Matrix tmp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			tmp.data[i][j] = this->data[i][j] * val;
		}
	}
	return tmp;
}

Matrix Matrix::MultiByMatrix(const Matrix & inMatrix) const
{
	assert(col == inMatrix.GetRow());
	Matrix tmp(row, inMatrix.GetColumn());

	for (int i = 0; i < row ; i++)
	{	
		for (int j = 0; j < col ; j++)
		{
			float res = 0.0f;
			for (int k = 0; k < row; k++)
			{
				res += this->data[i][k] * inMatrix.data[k][j];
			}
			tmp.data[i][j] = res;
		}
	}
	return tmp;
}

Matrix Matrix::operator+(const Matrix & inMatrix) const
{
	return Matrix::Add(inMatrix);
}

Matrix Matrix::operator-(const Matrix & inMatrix) const
{
	return Matrix::Subtract(inMatrix);
}
