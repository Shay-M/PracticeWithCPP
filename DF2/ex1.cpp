#include <iostream>
using namespace std;

typedef struct MyDate
{
	int year;
	int month;
	int day;
};


void swap(int *a, int *b) {// swap המקבלת שני מספרים מסוג int בצורת מצביע (pointer) ומחליפה ביניהם.
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapRef(int & a, int & b) {// swapRef המקבלת שני מספרים מסוג int בצורת  reference ומחליפה ביניהם
	int temp = a;
	a = b;
	b = temp;
}

int checkDate(int & year, int & month, int & day) {

	if ((month > 0 && month < 13) && (day > 0 && day < 32))
	{
		return 0;
	}
	else
	{
		swapRef(month, day);
		return 1;
	}

}


MyDate* inputDates(int numberOfDates) {

	MyDate * pNewDateArr = NULL;
	pNewDateArr = new MyDate[numberOfDates];

	for (int i = 0; i < numberOfDates; i++)
	{
		cout << "Date " << i + 1 << endl;

		cout << "year  month year :" << endl;
		cin >> pNewDateArr[i].year >> pNewDateArr[i].month >> pNewDateArr[i].day;

		checkDate(pNewDateArr[i].year, pNewDateArr[i].month, pNewDateArr[i].day);
		cout << "day is :" << pNewDateArr[i].day << endl;

	}

	return pNewDateArr;

}

void printDates(MyDate* pNewDateArr, int numberOfDates) {
	int count = 0;

	for (int i = 0; i < numberOfDates; i++)
	{
		
		if (!checkDate(pNewDateArr[i].year, pNewDateArr[i].month, pNewDateArr[i].day))
		{
			count++;
		}

		cout << endl << "year: " << pNewDateArr[i].year << " month: " << pNewDateArr[i].month << " " << " day: " << pNewDateArr[i].day << endl;
		cout << endl << "num err: " << count << endl;
	}
}

void main() {

	int a = 1;
	int b = 2;

	cout << "a: " << a << " b: " << b << endl;
	swap(&a, &b);
	cout << "a: " << a << " b: " << b << endl;

	cout << endl;

	cout << "a: " << a << " b: " << b << endl;
	swapRef(a, b);
	cout << "a: " << a << " b: " << b << endl;

	cout << endl;

	int year = 1999;
	int month = 13;
	int day = 1;

	/*int year;
	cin >> year;
	int month;
	cin >> month;
	int day;
	cin >> day;*/


	cout << endl;
	cout << "year: " << year << " month: " << month << " " << " day: " << day << endl;

	checkDate(year, month, day);

	cout << endl;
	cout << "year: " << year << " month: " << month << " " << " day: " << day << endl;

	int numberOfDates;
	cout << "number Of Dates: ";
	cin >> numberOfDates;

	MyDate * pNewDateArr = inputDates(numberOfDates);

	printDates(pNewDateArr, numberOfDates);

	delete[]pNewDateArr;
	pNewDateArr = NULL;



}