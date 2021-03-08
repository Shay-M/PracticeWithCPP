#ifndef INTERVAL_H
#define INTERVAL_H

#define INTERSECTION_ERR -1
#define UNION_ERR -2

#include <algorithm>
#include "iprintable.h"

template <typename T>
class Interval : public IPrintable
{
public:
    Interval(){};
    Interval(const T &start, const T &end) : _start(start), _end(end)
    {
        if(_start > _end)
            _err = UNION_ERR;
    }

    bool isEmpty() const
    {
        return _start == _end;
    }

    bool isBefore(const Interval<T> &other) const
    {
        return _end <= other._start;
    }

    bool isAfter(const Interval<T> &other) const
    {
        return _start > other._end;
    }

    bool intersects(const Interval<T> &other) const
    {
        return _start < other._end && _end > other._start;
    }

    bool contains(const T &other) const
    {
        return _start < other && _end > other;
    }

    bool operator==(const Interval<T> &other)
    {
        return (_start == other._start && _end == other._end);
    }

    Interval<T> operator&&(Interval<T> &other)
    {
        // intersection = empty group
        if (isForeign(other) || _end == other._start)
        {
            _err = INTERSECTION_ERR;
            return *this;
        }

        if ((other.contains(_start) && other.contains(_end)) || other == *this)
            return *this;

        if(contains(other._start) && contains(other._end))
            return other;

        return Interval<T>(std::max(_start, other._start), std::min(_end, other._end));
    }

    Interval<T> operator||(Interval<T> &other)
    {
        if(isForeign(other) || _end == other._start)
        {
            _err = UNION_ERR;
            return *this;
        }
        if ((other.contains(_start) && other.contains(_end)) || other == *this)
            return other;

        if (contains(other._start) && contains(other._end))
            return *this;

        return Interval<T>(std::min(_start, other._start), std::max(_end, other._end));
    }

    bool isValid() const
    {
        return _err == 0;
    }

    int getProblem() const
    {
        return _err;
    }

private:
    virtual void Print(std::ostream &out) const override
    {
        if(isValid())
            out << "(" << _start << ", " << _end << ")";
        else
            out << ((getProblem() == INTERSECTION_ERR) ? "EMPTY" : "Invalid interval");
    }
    virtual void Input(std::istream &) override {}
    bool isForeign(const Interval<T> &other) const
    {
        return other.isAfter(*this) || other.isBefore(*this);
    }

    T _start, _end;
    int _err = 0;
};
#endif