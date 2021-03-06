#pragma once



class Circle
{
public:
	Circle();
	~Circle();
	void set(double x, double y, double r); //  צריך להגדיר מהמחזיר
	double getX();
	double getY();
	double getR();
	void printMy();
	double getArea();
	double getPerimeter();
	int HitPoint(int x, int y);
	int HitArea(Circle c);

private:
	double _x;
	double _y;
	double _r;
	static const double _PI;
};