#pragma once
#include <string>// ���� ������ �� �� �������
using namespace std;



class Customer
{
public:
	Customer(string _name);
	~Customer();
	string _getName();
	double _getNumber();
	double _getBalance();
	void _deposit(double _money);//������ �����
	bool _withdraw(double _money);//������� �����
	void _printMe();
	

private:
	double _AccountNumber;
	double _AccountBalance;
	string NAME;
	static double NUM; // static ��� �� ���� ������ ���� 
	
};



