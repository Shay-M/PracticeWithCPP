#pragma once
#include <string>// צריך להחריז כי פה משתמשים
using namespace std;



class Customer
{
public:
	Customer(string _name);
	~Customer();
	string _getName();
	double _getNumber();
	double _getBalance();
	void _deposit(double _money);//פונקצת הפקדה
	bool _withdraw(double _money);//פונקצית משיכה
	void _printMe();
	

private:
	double _AccountNumber;
	double _AccountBalance;
	string NAME;
	static double NUM; // static ופה יש צורך להחריז עליו 
	
};



