#ifndef DATE_H
#define DATE_H

#define DAY_ERR -1
#define MONTH_ERR -2
#define LEAPYEAR_ERR -3

#include <iostream>
#include <array>
#include "icomparable.h"
#include "iprintable.h"

class Date : public IComparable<Date>, public IPrintable
{
public:
    Date(int = 1, int = 1, int = 1);

    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    virtual bool operator<(const Date &) const override;
    virtual bool operator>(const Date &) const override;
    virtual bool operator<=(const Date &) const override;
    virtual bool operator>=(const Date &) const override;
    virtual bool operator==(const Date &) const override;
    virtual bool operator!=(const Date &) const override;
    
    static bool leapYear(int); // is date in a leap year?
    void validate();
    int isValid() const;
    int getProblem() const;

private:
    virtual void Print(std::ostream &) const override;
    virtual void Input(std::istream &) override;
    static const std::array<int, 13> days; // days per month

    int _day, _month, _year, _err;
};
#endif
