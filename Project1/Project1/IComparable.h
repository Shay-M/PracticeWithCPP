#ifndef ICOMPERABLE_H
#define ICOMPERABLE_H

template <typename T>
class IComparable
{
public:
    virtual ~IComparable() {}

    virtual bool operator<(const T &) const = 0;
    virtual bool operator>(const T &) const = 0;
    virtual bool operator<=(const T &) const = 0;
    virtual bool operator>=(const T &) const = 0;
    virtual bool operator==(const T &) const = 0;
    virtual bool operator!=(const T &) const = 0;

private:
};
#endif