#pragma once

class Rational
{
public:
	Rational();
	~Rational();
	Rational(int num);
	Rational &operator = (Rational &R);//צריך להחזיר Rational &
	Rational &operator + (Rational &R);
	Rational &operator - (Rational &R);
	Rational &operator * (Rational &R);
	Rational &operator / (Rational &R);
private:
	int _mona;
	int _mkna;
};

