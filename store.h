#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#include "product.h"
#include <list>

class store
{
    float money ;
    list<product *> products ;
public:
    store():money(0.0){} ;
    store(int m) : money(m){} ;
    store(const store &ss):products(ss.products),money(ss.money) {} ;
    template <typename T> bool addnew(const T &p);
    bool buy(const product &p,int howmany,float price) ;
    bool sell(const product &p,int homany) ;
    product * seek(const product &p) ;
    void addmoney(float m) { money += m ; } ;
    float mon() { return money ;  } ;
    void viewall() ;
    void viewcategory(int) ;
    void viewbrand(string b) ;
    bool withdraw(const product &p) ;
    ~store() ;

};

template <typename T>
bool store::addnew(const T &p)
{
    T *t ;
    if ( seek(p) != nullptr ) return false ;
    t = new T(p) ;
    products.push_back(t) ;
    products.sort() ;
    return true ;
}

#endif // STORE_H_INCLUDED
