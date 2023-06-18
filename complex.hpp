#ifndef __COMPLEX__
#define __COMPLEX__

class complex {
public:
    complex (double r = 10, double i = 20)
        : re(r), im(i)
    {}
    //complex (double r = 10) //wrong! ambiguous - calling complex c1 will cause confused with the first construction function.
    complex (double r)
        : re(0), im(0) 
    {}
    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }

    static complex& getInstance();

private:
    double re, im;
};

template<typename T>
class complex_ext {
public:
    complex_ext (T r = 0, T i = 0)
        : re (r), im (i)
    { }
    complex_ext & operator += (const complex_ext&);
    T real () const { return re; }
    T imag () const { return im; }
private:
    T re, im;

    // friend complex_ext& __doapl (complex_ext*, const complex_ext&);
};


class Func {
public:
    int value;
    Func();
    virtual ~Func();
    const int getValue();
    int getValue2 () const ;
};

#endif