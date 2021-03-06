#include "Circle.h" 
#include <iostream>

using namespace std;

const double Circle::_PI = 3.14159265359;// לשים קונסט 

Circle::Circle()
{

}

Circle::~Circle()
{
}
//inline
void Circle::set(double x, double y, double r)
{
	_x = x;
	_y = y;
	_r = r;
}

double Circle::getX()
{
	return _x;
}

double Circle::getY()
{
	return _y;
}

double Circle::getR()
{
	return _r;
}

void Circle::printMy()
{
	cout << this << endl;
	cout << "X is: " << _x << endl;
	cout << "Y is: " << _y << endl;
	cout << "R is: " << _r << endl;
}

double Circle::getArea()
{
	return _PI * _r*_r;
}

double Circle::getPerimeter()
{

	return _PI * 2 * _r;
}

int Circle::HitPoint(int x, int y)
{
	if ((x - _r <= _x)&&(y - _r <= _y))
		return 1;
	else return 0;

}

int Circle::HitArea(Circle c)
{
	if ((c.getX() - _r <= _x) && (c.getY() - _r <= _y))
		return 1;
	else return 0;
}

