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
void Circle::set(double x, double y, unsigned int r)
{
	_x = x;
	_y = y;
	_r = r;
}

inline int Circle::getX()
{
	return _x;
}

inline int Circle::getY()
{
	return _y;
}

inline int Circle::getR()
{
	return _r;
}

void Circle::printMy()
{
	cout << "X is: " << _x << endl;
	cout << "Y is: " << _y << endl;
	cout << "R is: " << _r << endl;
}

int Circle::getArea()
{
	return _PI * _r*_r;
}

int Circle::getPerimeter()
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
	if ((c.getX - _r <= _x) && (c.getY - _r <= _y))
		return 1;
	else return 0;
}

