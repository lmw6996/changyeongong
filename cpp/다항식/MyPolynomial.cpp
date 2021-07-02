#include "MyPolynomial.h"

// Constructor
myPolynomial::myPolynomial(int c, unsigned e) 
{
	if (c == 0)	// the zero polynomial has degree -1
	{
		terms.clear();
		degree = -1;
	}
	else
	{
		terms.clear();
		terms.push_back(myTerm(c,e));
		degree = e;
	}
}

// Constructor
myPolynomial::myPolynomial(int nTerms, int mono[]) 
{
	terms.clear();

	for(int i=0; i<nTerms; i++)
		terms.push_back(myTerm(mono[i*2], mono[i*2+1]));
	
	reduce();
}

// copy constructor
myPolynomial::myPolynomial(const myPolynomial &poly) : terms(poly.terms), degree(poly.degree)
{
}

// overloaded operator ==
bool myPolynomial::operator == (const myPolynomial& poly) const
{
	return terms == poly.terms;
}

// overloaded operator !=
bool myPolynomial::operator != (const myPolynomial& poly) const
{
	return terms != poly.terms;
}

// overloaded operator +=
myPolynomial& myPolynomial::operator += (const myPolynomial& poly)
{
	*this = *this + poly;
	return *this;
}

// overloaded operator -=
myPolynomial& myPolynomial::operator -= (const myPolynomial& poly)
{
	*this = *this - poly;
	return *this;
}

// overloaded operator *=
myPolynomial& myPolynomial::operator *= (const myPolynomial& poly)
{
	*this = *this * poly;
	return *this;
}

// overloaded operator *=
myPolynomial& myPolynomial::operator *= (int k)
{
	*this = *this * k;
	return *this;
}

// overloaded operator -
myPolynomial myPolynomial::operator -() const
{
	myPolynomial p(*this);

	for(termIt it=p.terms.begin(); it!=p.terms.end(); it++)
		it->coeff *= -1;

	return p;
}

// overloaded operator *
myPolynomial myPolynomial::operator *(int k) const
{
	myPolynomial p;

	p = k * *this;

	return p;
}

// overloaded operator +
myPolynomial myPolynomial::operator +(const myPolynomial &poly) const
{
	myPolynomial p;

	p.degree = max(degree, poly.degree);
	p.terms = terms;

	for(termCIt it = poly.terms.begin(); it != poly.terms.end(); it++)
		p.terms.push_back(*it);

	p.reduce();
	return p;
}

// overloaded operator -
myPolynomial myPolynomial::operator -(const myPolynomial &poly) const
{
	return *this + -poly;
}

// overloaded operator *
myPolynomial myPolynomial::operator *(const myPolynomial &poly) const
{
	myPolynomial p;

	p.degree = degree + poly.degree;

	for(termCIt it1 = terms.begin(); it1 != terms.end(); it1++)
		for(termCIt it2 = poly.terms.begin(); it2 != poly.terms.end(); it2++)
		{
			int newExp = it1->exp + it2->exp;
			int newCoeff = it1->coeff * it2->coeff;
			termIt it = p.terms.begin();
/*
			for(; it != p.terms.end(); it++)
				if(it->exp == newExp) break;

			if(it->exp == newExp)
				it->coeff += newCoeff;
			else
				p.terms.push_back(myTerm(newCoeff, newExp));
*/
			p.terms.push_back(myTerm(newCoeff, newExp));
		}

	p.reduce();
	return p;
}

long myPolynomial::operator() (int x) const
{
	termCIt it = terms.begin();
	
	if (it == terms.end())
		return 0;

	int y = it->coeff;
	unsigned e1 = it->exp;

	while(++it != terms.end())
	{
		int e2 = it->exp;

		y *= ipow(x, e1-e2);
		y += it->coeff;
		e1 = e2;
	}

	return y*ipow(x, e1);
}

int myPolynomial::getDegree() const
{
	return degree;
}

unsigned myPolynomial::getNumTerms() const
{
	return terms.size();
}

myPolynomial operator *(int k, const myPolynomial &poly)
{
	if (k==0)
		return myPolynomial::ZERO;

	myPolynomial p(poly);
	for(myPolynomial::termIt it=p.terms.begin(); it != p.terms.end(); it++)
        it->setCoeff(it->getCoeff() * k);

	return p;
}

// derivative of a poly
myPolynomial myPolynomial::ddx() const
{
	if (degree < 0)
		return myPolynomial::ZERO;
	
	myPolynomial p;
	p.degree = (degree > 0) ? degree-1 : 0;
	for(myPolynomial::termCIt it=terms.begin(); it != terms.end(); it++)
		if (it->getExp() > 0)
			p.terms.push_back(it->ddx());

	return p;
}

// output operator
ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
	if (poly == myPolynomial::ZERO)
		return outStream << 0;

	myPolynomial::termCIt it = poly.terms.begin();
	outStream << *it++;

	while (it != poly.terms.end() )
		if (it->getCoeff() < 0)
			outStream << *it++;
		else
			outStream << "+" << *it++;

    return outStream;
}

// power x^n for an integer x
long myPolynomial::ipow(int x, int n) const
{
	long val = 1;

	for(int i=0; i<n; i++)
		val *= x;

	return val;
}

// reduce the terms in a polynomial data structure
void myPolynomial::reduce()
{
	if (*this == ZERO)
		return;

	// order the terms w.s.t the degree of terms
	terms.sort();

	// reduce the terms
	termIt it1, it2;
	it1 = it2 = terms.begin();

	while(it1 != terms.end())
	{
		while(++it2 != terms.end() && it2->exp == it1->exp)
			it1->coeff += it2->coeff;
		if(it1->coeff == 0)
			terms.erase(it1, it2);
		else
			terms.erase(++it1, it2);
		it1 = it2;
	}

	if(terms.size() ==0)
		degree = 0;
	else
		degree = terms.begin()->exp;
}

const myPolynomial myPolynomial::ZERO(0);	// the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0);	// the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1);	// the monomial P(x) = x