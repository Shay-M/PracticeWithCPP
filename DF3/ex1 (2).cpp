#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "Circle.h" //צריך להגדיר את הספריה 



void main() {

	Circle mycircel1;
	mycircel1.set(1, 1, 5);

	Circle mycircel2;
	mycircel2.set(10, 10, 5);

	mycircel1.printMy();
	cout << endl;
	mycircel2.printMy();

	cout << "mycircel1.getArea: " << mycircel1.getArea() << endl;
	cout << "mycircel1.getPerimeter: " << mycircel1.getPerimeter() << endl;

	cout << endl;

	cout << "mycircel2.getArea: " << mycircel2.getArea() << endl;
	cout << "mycircel2.getPerimeter: " << mycircel2.getPerimeter() << endl;
		
	mycircel1.set(mycircel1.getX()+5, mycircel1.getY()+5, mycircel1.getR());
	//cout << "HitPoint: " << mycircel1.HitPoint(5, 5) << endl;
/*	//mycircel1.set(1, 1, 1);
	mycircel1.printMy();

	*/


}