#include <iostream>
#include <iomanip>
#include <string.h>
#include "date.h"

using namespace std;

const array<int, 13> Date::days =
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int day, int month, int year)
{
    _err = 0;
    setMonth(month);
    setDay(day);
    setYear(year);
}

void Date::setDay(int d)
{
    _err = 0;
    _day = d;
    validate();
}

void Date::setMonth(int m)
{
    _err = 0;
    _month = m;
    validate();
}

void Date::setYear(int y)
{
    _err = 0;
    _year = y;
    validate();
}

int Date::getDay() const
{
    return _day;
}

int Date::getMonth() const
{
    return _month;
}

int Date::getYear() const
{
    return _year;
}

bool Date::operator==(const Date &date) const
{
    return (_day == date._day && _month == date._month && _year == date._year);
}

bool Date::operator!=(const Date &date) const
{
    return !(*this == date);
}

bool Date::operator<(const Date &date) const
{
    if (*this == date)
        return false;
    if (_year < date._year)
        return true;
    else if (_year == date._year)
    {
        if (_month < date._month)
            return true;
        else if (_month == date._month)
        {
            if (_day < date._day)
                return true;
        }
    }
    return false;
}

bool Date::operator>(const Date &date) const
{
    if (*this == date)
        return false;
    return !(*this < date);
}

bool Date::operator<=(const Date &date) const
{
    return (*this < date || *this == date);
}

bool Date::operator>=(const Date &date) const
{
    return (*this > date || *this == date);
}

void Date::Print(std::ostream & out) const
{
    if (isValid())
    {
        out << setfill('0') << setw(2) << _day << "/"
            << setw(2) << _month << "/";
        out << _year;
    }
    else
    {
        switch (getProblem())
        {
        case DAY_ERR:
            out << "Illegal day for month";
            break;
        case MONTH_ERR:
            out << "Illegal month";
            break;
        case LEAPYEAR_ERR:
            out << "Not a leap year";
            break;
        default:
            break;
        }
    }
}

void Date::Input(std::istream &in)
{
    _err = 0;
    char *str = new char[1000];
    in.getline(str, 1000);

    str = strtok(str, "/");
    setDay(stoi(str));

    str = strtok(NULL, "/");
    setMonth(stoi(str));

    str = strtok(NULL, " ");
    setYear(stoi(str));

    validate();
}

// if the year is a leap year
bool Date::leapYear(int testYear)
{
    if (testYear % 400 == 0 ||
        (testYear % 100 != 0 && testYear % 4 == 0))
        return true; // a leap year
    else
        return false; // not a leap year
}

// check for errors
void Date::validate()
{
    if (!(_month >= 1 && _month <= 12))
    {
        _err = MONTH_ERR;
        return;
    }

    if (!leapYear(_year) && _month == 2 && _day > 28)
    {
        _err = LEAPYEAR_ERR;
        return;
    }

    if (!((_day >= 1 && _day <= days[_month]) ||
    (_month == 2 && leapYear(_year) && _day >= 1 && _day <= 29)))
    {
        _err = DAY_ERR;
        return;
    }
}

int Date::isValid() const
{
    return _err == 0;
}

int Date::getProblem() const
{
    return _err;
}
