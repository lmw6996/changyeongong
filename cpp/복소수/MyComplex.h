/*************************************************************************
*                                                                        *
* ���� 000 : ������ ���Ҽ�(Complex Number) Class                         *
*                                                                        *
*************************************************************************/

#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

#include <iostream>
using namespace std;

class myComplex {

	// ����� �Լ�
	friend ostream &operator <<(ostream &outStream, const myComplex& number);
	friend istream &operator >>(istream &inStream, myComplex& number);
	
	friend myComplex operator +(int value, const myComplex& number);
	friend myComplex operator -(int value, const myComplex& number);
	friend myComplex operator *(int value, const myComplex& number);

public:
    // Constructor (������)
    myComplex(int real = 0, int imag = 0);
	// Copy constructor (���� ������)
	myComplex(const myComplex& number);

	// Accessor functions (������)
	int getRealPart() const;
	int getImaginaryPart() const;

	// Mutator functions (������)
	void setRealPart(int real);
	void setImaginaryPart(int imag);
	void set(int real, int imag);

    // Overloaded binary operators
    myComplex operator +(const myComplex& number) const;
    myComplex operator -(const myComplex& number) const;
    myComplex operator *(const myComplex& number) const;
    myComplex operator +(int value) const;
    myComplex operator -(int value) const;
    myComplex operator *(int value) const;

	// Overloaded assignment operators
    myComplex& operator =(const myComplex& number);
    myComplex& operator +=(const myComplex& number);
    myComplex& operator -=(const myComplex& number);
    myComplex& operator *=(const myComplex& number);
    myComplex& operator =(int value);
    myComplex& operator +=(int value);
    myComplex& operator -=(int value);
    myComplex& operator *=(int value);

	// Overloading relational operators
	bool operator ==(const myComplex& number) const;
	bool operator !=(const myComplex& number) const;
	bool operator >(const myComplex& number) const;
	bool operator >=(const myComplex& number) const;
	bool operator <(const myComplex& number) const;
	bool operator <=(const myComplex& number) const;

    // Overloaded unary operators
    myComplex operator -();		// unary minus
	myComplex operator ~();		// conjugate operator
    myComplex& operator ++();	// prefix ++
    myComplex& operator --();	// prefix --
    myComplex operator ++(int);	// postfix ++
    myComplex operator --(int);	// postfix --

private:
	int realPart;
	int imaginaryPart;
	int norm() const;
};

#endif

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

