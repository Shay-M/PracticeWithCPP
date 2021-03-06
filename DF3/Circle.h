#pragma once



class Circle
{
public:
	Circle();
	~Circle();
	void set(double, double, unsigned int); //  צריך להגדיר מהמחזיר
	int getX();
	int getY();
	int getR();
	void printMy();
	int getArea();
	int getPerimeter();
	int HitPoint(int x, int y);
	int HitArea(Circle c);

private:
	double _x;
	double _y;
	unsigned int _r;
	static const double _PI;
};