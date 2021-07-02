/*************************************************************************
*                                                                        *
* ¹®Á¦ 000 : Simple Matrix Class                                         *
*                                                                        *
*************************************************************************/

#include "MyMatrix.h"

// Constructor
myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			pData[i][j] = initValue;
}

myMatrix::myMatrix(int nRows, int nCols, int *data) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			pData[i][j] = data[i*cols+j];
}

myMatrix::myMatrix(int nRows, int nCols, int **data) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			pData[i][j] = data[i][j];
}

myMatrix::~myMatrix()
{
	if (pData != NULL)
		deleteMemory();
}

// Copy constructor
myMatrix::myMatrix(const myMatrix& mat) :
rows(mat.rows), cols(mat.cols), pData(NULL)
{
	allocateMemory();

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			pData[i][j] = mat.pData[i][j];
}

// Accessor functions
int myMatrix::getRows() const
{
	return rows;
}

int myMatrix::getCols() const
{
	return cols;
}

int* myMatrix::operator [](int i) const
{
	if((i < 0) || (i >= rows))
		errorMessage("Accessing out-of-bound value of a matrix");

	return pData[i];
}

int& myMatrix::operator ()(int i, int j) const
{
	if((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
		errorMessage("Accessing out-of-bound value of a matrix");

	return pData[i][j];
}

// Overloaded binary operators
myMatrix myMatrix::operator +(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage("cannot add two matrices of different size");

	myMatrix tmpMat(rows, cols);

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			tmpMat[i][j] = pData[i][j] + mat.pData[i][j];

	return tmpMat;
}

myMatrix myMatrix::operator -(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage("cannot do subtraction between two matrices of different size");

	myMatrix tmpMat(rows, cols);

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			tmpMat[i][j] = pData[i][j] - mat.pData[i][j];

	return tmpMat;
}

myMatrix myMatrix::operator *(const myMatrix& mat) const
{
	if (cols != mat.rows)
		errorMessage("cannot do multiplication between the given two matrices");

	myMatrix tmpMat(rows, mat.cols);

	for(int i=0; i<tmpMat.rows; i++)
	{
		for(int j=0; j<tmpMat.cols; j++)
		{
			int sum = 0;
			
			for(int k=0; k<cols; k++)
				sum += pData[i][k] * mat.pData[k][j];

			tmpMat[i][j] = sum;
		}
	}

	return tmpMat;
}

myMatrix myMatrix::operator *(int value) const
{
	return value * (*this);
}

// Assignment operators
myMatrix& myMatrix::operator =(const myMatrix& mat)
{
	if(&mat == this)
		return *this;

	rows = mat.rows;
	cols = mat.cols;
	allocateMemory();

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			pData[i][j] = mat.pData[i][j];

	return *this;
}

myMatrix& myMatrix::operator +=(const myMatrix& mat)
{
	return (*this = *this + mat);	// inefficient code, but it's OK
}

myMatrix& myMatrix::operator -=(const myMatrix& mat)
{
	return (*this = *this - mat);	// inefficient code, but it's OK
}

myMatrix& myMatrix::operator *=(const myMatrix& mat)
{
	return (*this = *this * mat);	// inefficient code, but it's OK
}

myMatrix& myMatrix::operator *=(int value)
{
	return (*this = *this * value);	// inefficient code, but it's OK
}

// Overloading relational operators
bool myMatrix::operator ==(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		return false;

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			if(pData[i][j] != mat.pData[i][j]) 
				return false;

	return true;
}

bool myMatrix::operator !=(const myMatrix& mat) const
{
	return !((*this) == mat);
}

// Overloaded unary operators
myMatrix myMatrix::operator -() const		// unary minus
{
	myMatrix tmpMat(rows, cols);

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			tmpMat[i][j] = -pData[i][j];

	return tmpMat;
}

// transpose the matrix
myMatrix& myMatrix::transpose()
{
	myMatrix tmp(cols, rows);

	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			tmp.pData[j][i] = pData[i][j];
		}
	}

	return (*this = tmp);
}

// private functions
void myMatrix::allocateMemory()
{
	if (pData != NULL)
		deleteMemory();

	pData = new int * [rows];
	if(pData == NULL)
		errorMessage("Memory allocation error");

	pData[0] = new int [rows*cols];
	if(pData[0] == NULL)
	{
		delete [] pData;
		errorMessage("Memory allocation error");
	}

	for(int i=1; i<rows; i++)
		pData[i] = pData[0] + i * cols;
}

void myMatrix::deleteMemory()
{
	delete [] pData[0];
	delete [] pData;

	pData = NULL;
}

void myMatrix::errorMessage(string str) const
{
	cout << "Error: " << str << endl;
	exit(1);
}

// friend functions
myMatrix operator *(int value, const myMatrix& mat)
{
	myMatrix tmpMat(mat.rows, mat.cols);

	for(int i=0; i<mat.rows; i++)
		for(int j=0; j<mat.cols; j++)
			tmpMat[i][j] = value * mat.pData[i][j];

	return tmpMat;
}

ostream &operator <<(ostream &outStream, const myMatrix& mat)
{
	outStream << mat.rows << "*" << mat.cols << endl;

	for(int i=0; i<mat.rows; i++)
	{
		for (int j=0; j<mat.cols; j++)
			outStream << mat[i][j] << " ";
		outStream << endl;
	}

	return outStream;
}

istream &operator >>(istream &inStream, myMatrix& mat)
{
	mat.deleteMemory();

	inStream >> mat.rows >> mat.cols;

	mat.allocateMemory();

	for(int i=0; i<mat.rows; i++)
	{
		for (int j=0; j<mat.cols; j++)
			inStream >> mat[i][j];
	}

	return inStream;
}


/*************************************************************************
* (C) Copyright 2007 by Joonsoo Choi, Kwang-Soo Hahn                     *
* All Rights Reserved.                                                   *
*                                                                        *
* Permission is granted to any individual or institution to use, copy,   *
* modify, and distribute this code, provided that this complete          *
* copyright and permission notice is maintained, intact, in all copies   *
* and supporting documentation.                                          *
*                                                                        *
* DISCLAIMER: The authors and publisher make no warranty of any kind,    *
* expressed or implied, with regard to these codes. The authors and      *
* publisher shall not be liable in any event for incidental or           *
* consequential damages in connection with, or arising out of, the       *
* furnishing, performance, or use of these codes.                        *
*************************************************************************/

