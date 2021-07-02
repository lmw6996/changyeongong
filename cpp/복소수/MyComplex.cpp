/*************************************************************************
*                                                                        *
* ���� 000 : ������ ���Ҽ�(Complex Number) Class                         *
*                                                                        *
*************************************************************************/

#include "MyComplex.h"

// Constructor
myComplex::myComplex(int real, int imag)
{
	realPart = real;
	imaginaryPart = imag;
}

// Copy constructor
myComplex::myComplex(const myComplex& number)
{
	realPart = number.realPart;
	imaginaryPart = number.imaginaryPart;
}

// Accessor functions
int myComplex::getRealPart() const
{
	return realPart;
}

int myComplex::getImaginaryPart() const
{
	return imaginaryPart;
}

// Mutator functions
void myComplex::setRealPart(int real)
{
	realPart = real;
}

void myComplex::setImaginaryPart(int imag)
{
	imaginaryPart = imag;
}

void myComplex::set(int real, int imag)
{
	realPart = real;
	imaginaryPart = imag;
}

// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
	int newReal = realPart + number.realPart;
	int newImag = imaginaryPart + number.imaginaryPart;
	return myComplex (newReal, newImag);
}

myComplex myComplex::operator -(const myComplex& number) const
{
	int newReal = realPart - number.realPart;
	int newImag = imaginaryPart - number.imaginaryPart;
	return myComplex (newReal, newImag);
}

myComplex myComplex::operator *(const myComplex& number) const
{
	int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
	int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
	return myComplex (newReal, newImag);
}

/**********************************************************************************
* ��� �Լ��� ���� ����� ��
* �Ʒ� �� �Լ��� ���Ͽ�, ���� �Լ��� �پ��� ������� ������ �� ������ �� �� �ִ�.
* (��� 1) ������ ���Ҽ��� ��ȯ�� �Ŀ� �� ���Ҽ��� ���Ѵ�. 
*          ����� : ����������, ��ȿ������ �� �ִ�.
* (��� 2) ������ ���Ҽ��� ���� �����Ѵ�.
*          ����� : ȿ����������, �ڵ尡 �����ϰ� �� �� �ִ�.
* (��� 3) �̹� ������ �ٸ� �Լ��� ȣ���Ͽ� �����Ѵ�.
***********************************************************************************/ 
//
// ������ +(myComplex, integer)
// ���� : ������ ���Ҽ��� ��ȯ�� �Ŀ� �� ���Ҽ��� ���Ѵ�. (��� 1)
//
myComplex myComplex::operator +(int value) const
{
	return myComplex(value) + (*this);
}

//
// ������ -(myComplex, integer)
// ���� : ������ ���� ���Ҽ����� ����. (��� 2)
//
myComplex myComplex::operator -(int value) const
{
	int newReal = realPart - value;
	int newImag = imaginaryPart;
	return myComplex (newReal, newImag);
}

//
// ������ *(myComplex, integer)
// ���� : �̹� ������ �ٸ� �Լ� *(integer, myComplex)�� �̿��Ѵ�. (��� 3)
//
myComplex myComplex::operator *(int value) const
{
	return value * (*this);
}

// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
	this->realPart = number.realPart;
	this->imaginaryPart = number.imaginaryPart;
	return *this;
}

myComplex& myComplex::operator +=(const myComplex& number)
{
	realPart += number.realPart;
	imaginaryPart += number.imaginaryPart;
	return *this;
}

myComplex& myComplex::operator -=(const myComplex& number)
{
	realPart -= number.realPart;
	imaginaryPart -= number.imaginaryPart;
	return *this;
}

myComplex& myComplex::operator *=(const myComplex& number)
{
	int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
	int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;

	realPart = newReal;
	imaginaryPart = newImag;
	return *this;
}

myComplex& myComplex::operator =(int value)
{
	realPart = value;
	imaginaryPart = 0;
	return *this;
}

myComplex& myComplex::operator +=(int value)
{
	realPart += value;
	return *this;
}

myComplex& myComplex::operator -=(int value)
{
	realPart -= value;
	return *this;
}

myComplex& myComplex::operator *=(int value)
{
	realPart *= value;
	imaginaryPart *= value;
	return *this;
}

// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
	return (realPart == number.realPart) && 
		   (imaginaryPart == number.imaginaryPart);
}

bool myComplex::operator !=(const myComplex& number) const
{
	return !((*this) == number);
}

bool myComplex::operator >(const myComplex& number) const
{
	return norm() > number.norm();
}

bool myComplex::operator >=(const myComplex& number) const
{
	return !(norm() < number.norm());
}

bool myComplex::operator <(const myComplex& number) const
{
	return norm() < number.norm();
}

bool myComplex::operator <=(const myComplex& number) const
{
	return !(norm() > number.norm());
}

// Overloaded unary operators
myComplex myComplex::operator -()		// unary minus
{
	return myComplex(-realPart, -imaginaryPart);
}

myComplex myComplex::operator ~()		// conjugate operator
{
	return myComplex(realPart, -imaginaryPart);
}

myComplex& myComplex::operator ++()		// prefix ++
{
	realPart++;
	return *this;
}

myComplex& myComplex::operator --()		// prefix --
{
	realPart--;
	return *this;
}

myComplex myComplex::operator ++(int)	// postfix ++
{
	myComplex result (*this);
	realPart++;
	return result;
}

myComplex myComplex::operator --(int)	// postfix --
{
	myComplex result (*this);
	realPart--;
	return result;
}

// private function
int myComplex::norm() const
{
	return realPart * realPart + imaginaryPart * imaginaryPart;
}

// friend functions
myComplex operator +(int value, const myComplex& number)
{
	int newReal = value + number.realPart;
	int newImag = number.imaginaryPart;
	return myComplex (newReal, newImag);
}

myComplex operator -(int value, const myComplex& number)
{
	int newReal = value - number.realPart;
	int newImag = -number.imaginaryPart;
	return myComplex (newReal, newImag);
}

myComplex operator *(int value, const myComplex& number)
{
	int newReal = value * number.realPart;
	int newImag = value * number.imaginaryPart;
	return myComplex (newReal, newImag);
}

ostream &operator <<(ostream &outStream, const myComplex& number)
{
	outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
	return outStream;
}

istream &operator >>(istream &inStream, myComplex& number)
{
	inStream >> number.realPart >> number.imaginaryPart;
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

