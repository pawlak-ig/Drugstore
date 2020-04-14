#ifndef SHOWERGEL_H_INCLUDED
#define SHOWERGEL_H_INCLUDED
#include "product.h"

class showergel:public product
{
    const static int category = 1;
    double volume ;
public:
    showergel(double v = 0):product(),volume(v) {} ;
    showergel(string n,string b,int a ,int wn, int s,float rp,float wp,double v):product(n,b,a,wn,s,rp,wp),volume(v) {} ;
    showergel(const showergel &) ;
    virtual void operator =(const showergel &) ;
    virtual void view() ;
    virtual int cat() {return category ; } ;
    ~showergel(){} ;
};

#endif // SHOWERGEL_H_INCLUDED
