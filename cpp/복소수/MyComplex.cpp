/*************************************************************************
*                                                                        *
* 문제 000 : 간단한 복소수(Complex Number) Class                         *
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
* 멤버 함수의 구현 방법의 예
* 아래 세 함수를 통하여, 같은 함수를 다양한 방법으로 구현할 수 있음을 알 수 있다.
* (방법 1) 정수를 복소수로 변환한 후에 두 복소수를 더한다. 
*          장단점 : 간단하지만, 비효율적일 수 있다.
* (방법 2) 정수와 복소수를 직접 연산한다.
*          장단점 : 효율적이지만, 코드가 복잡하고 길 수 있다.
* (방법 3) 이미 구현된 다른 함수를 호출하여 구현한다.
***********************************************************************************/ 
//
// 연산자 +(myComplex, integer)
// 구현 : 정수를 복소수로 변환한 후에 두 복소수를 더한다. (방법 1)
//
myComplex myComplex::operator +(int value) const
{
	return myComplex(value) + (*this);
}

//
// 연산자 -(myComplex, integer)
// 구현 : 정수를 직접 복소수에서 뺀다. (방법 2)
//
myComplex myComplex::operator -(int value) const
{
	int newReal = realPart - value;
	int newImag = imaginaryPart;
	return myComplex (newReal, newImag);
}

//
// 연산자 *(myComplex, integer)
// 구현 : 이미 구현된 다른 함수 *(integer, myComplex)를 이용한다. (방법 3)
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

