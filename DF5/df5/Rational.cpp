#include "Rational.h"
#include <iostream>


Rational::Rational()
{

}

Rational::~Rational()
{

}

Rational::Rational(int num)
{
	_mona = num;
	_mkna = 1;
}

Rational & Rational::operator=(Rational & R)
{

	_mona = R._mona;
	_mkna = R._mkna;
	return *this;
}

Rational & Rational::operator+(Rational & R)
{
	Rational TRat;
	int tempBiger = _mona;
	int tempSmall = _mkna;

	if (_mkna > _mona) {
		tempBiger = _mkna;
		tempSmall = _mona;
	}
	
	_mkna /= Gcd(tempSmall, tempBiger);

	R._mkna /= Gcd(tempSmall, tempBiger);


	_mona += R._mona;
	_mkna += R._mkna;
	return *this;
}

Rational & Rational::operator-(Rational & R)
{
	// TODO: insert return statement here
}

Rational & Rational::operator*(Rational & R)
{
	// TODO: insert return statement here
}

Rational & Rational::operator/(Rational & R)
{
	// TODO: insert return statement here
}


int Gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return Gcd(b, a % b);
}