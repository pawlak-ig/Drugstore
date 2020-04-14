#ifndef EYELINER_H_INCLUDED
#define EYELINER_H_INCLUDED
#include "product.h"

class eyeliner:public product
{
    const static int category = 2;
    enum {black,blue,brown,purple,pink,glittery};
    string colournames[6] = {"black","blue","brown","purple","pink","glittery"} ;
    int colour ;
public:
    eyeliner(int c = 0 ):product(),colour(c){} ;
    eyeliner(string n,string b,int a ,int wn, int s,float rp,float wp,int c):product(n,b,a,wn,s,rp,wp),colour(c){} ;
    eyeliner(const eyeliner &) ;
    virtual void operator =(const eyeliner &) ;
    virtual void view() ;
    virtual int cat() {return category ; } ;
    ~eyeliner(){} ;

};


#endif // EYELINER_H_INCLUDED
