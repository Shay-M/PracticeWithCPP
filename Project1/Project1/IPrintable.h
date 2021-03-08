#ifndef IPRINTABLE_H
#define IPRINTABLE_H

class IPrintable
{
    friend std::ostream &operator<<(std::ostream &out, const IPrintable &obj)
    {
        obj.Print(out);
        return out;
    }
    friend std::istream &operator>>(std::istream &in, IPrintable &obj)
    {
        obj.Input(in);
        return in;
    }

public:
    virtual ~IPrintable() {}
private:
    virtual void Print(std::ostream &) const = 0;
    virtual void Input(std::istream &) = 0;
};
#endif