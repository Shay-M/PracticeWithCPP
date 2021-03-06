#include <iostream>
#include "Customer.h"

double Customer::NUM = 1;//יש צורך לאתחל אותו

Customer::Customer(string _name)
{
	NAME = _name;
	_AccountBalance = 0;
	_AccountNumber = NUM++;

}

Customer::~Customer()
{
}

string Customer::_getName()
{
	return this->NAME;
}


double Customer::_getNumber()
{
	return this->_AccountNumber;
}

double Customer::_getBalance()
{
	return this->_AccountBalance;
}

void Customer::_deposit(double _money)//פונקצת הפקדה
{
	_AccountBalance += _money;
}

bool Customer::_withdraw(double _money)//פונקצית משיכה
{
	if (_AccountBalance- _money>=0)
	{
		_AccountBalance -= _money;
		return true;
	}else return false;
}

void Customer::_printMe()
{
	cout << endl;
	cout << "Name: " << this->NAME << endl;
	cout << "AccountNumber: " << this->_AccountNumber << endl;
	cout << "AccountBalance: " << this->_AccountBalance << endl;
	cout  << endl;
}

