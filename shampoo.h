#ifndef SHAMPOO_H_INCLUDED
#define SHAMPOO_H_INCLUDED
#include "product.h"

class shampoo:public product
{
    const static int category = 0;
    double volume ;
    enum {moisturising,volumising,nutritiouning,antidandruff,repairing,smoothing};
    string typenames[6] = {"moisturising","volumising" , "nutritiouning" , "anti-dandruff" , "repairing" , "smothing"} ;
    int type ;
public:
    shampoo(double v= 0 ):product(),volume(v){} ;
    shampoo(string n,string b,int a ,int wn, int s,float rp,float wp,double v,int t):product(n,b,a,wn,s,rp,wp),volume(v),
        type(t){} ;
    shampoo(const shampoo &) ;
    virtual void operator =(const shampoo &) ;
    virtual void view() ;
    virtual int cat() {return category ; } ;
    ~shampoo(){} ;

};


#endif // SHAMPOO_H_INCLUDED
