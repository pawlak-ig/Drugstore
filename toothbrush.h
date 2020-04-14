#ifndef TOOTHBRUSH_H_INCLUDED
#define TOOTHBRUSH_H_INCLUDED
#include "product.h"

class toothbrush:public product
{
    const static int category = 3;
    int pieces ;
public:
    toothbrush(int p = 0 ):product(),pieces(p){} ;
    toothbrush(string n,string b,int a ,int wn, int s,float rp,float wp,int p):product(n,b,a,wn,s,rp,wp),pieces(p){} ;
    toothbrush(const toothbrush &) ;
    virtual void operator =(const toothbrush &) ;
    virtual void view() ;
    virtual int cat() {return category ; } ;
    ~toothbrush(){} ;
};

#endif // TOOTHBRUSH_H_INCLUDED
