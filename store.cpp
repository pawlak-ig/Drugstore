#include "store.h"

bool store::sell(const product &p,int howmany)
{
    product * w;
    if ( (w = seek(p)) == nullptr ) return false ;
    money += w->sell(howmany) ;
    return true ;
}
bool store::buy(const product &p,int howmany,float price)
{
    product *w ;
    if ( (w = seek(p)) != nullptr )
    {
        if ( howmany*price <= money )
        {
            money -= w->buy(howmany,price) ;
            return true ;
        }
    }
    else return false ;
}
product * store::seek(const product &p)
{
    product *w ;
    list<product *>::iterator iter ;
    for (iter = products.begin() ; iter != products.end() ; iter++)
    {
        if ( **iter == p )
        {
            w = *iter ;
            return w ;
        }
    }
    return nullptr ;
}
void store::viewall()
{
    cout << "Balance: " << money << endl << endl ;
    cout << "All products" << endl ;
    list<product *>::iterator iter ;
    for (iter = products.begin() ; iter != products.end() ; iter++)
    {
        (*iter)->view() ;
        cout << endl ;
    }
}
void store::viewcategory(int c)
{
    list<product *>::iterator iter ;
    for (iter = products.begin() ; iter != products.end() ; iter++)
    {
        if ( (*iter)->cat() == c )(*iter)->view() ;
        cout << endl ;
    }
}
void store::viewbrand(string b)
{
    list <product*>::iterator iter ;
    for (iter = products.begin() ; iter != products.end() ; iter++)
    {
        if ( (*iter)->brandd() == b )(*iter)->view() ;
        cout << endl ;
    }
}
bool store::withdraw(const product &p)
{
    product * w ;
    w = seek(p) ;
    if ( w == nullptr) return false;
    products.remove(w) ;
    delete w ;
    return true ;
}
store::~store()
{
    list<product *>::iterator iter ;
    for (iter = products.begin() ; iter != products.end() ; iter++)
    {
        delete (*iter) ;
    }
}

