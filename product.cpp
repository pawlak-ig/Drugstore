#include "product.h"

product::product()
{
    name = brand = "Unknown" ;
    available = wnumber = sex = retailprice = wholesaleprice = 0 ;

}

product::product(string n,string b,int a ,int wn, int s,float rp,float wp)
{
    name = n ;
    brand = b ;
    available = a ;
    wnumber = wn ;
    sex = s ;
    retailprice = rp ;
    wholesaleprice = wp ;
}
product::product(char * n,char * b,int a ,int wn, int s,float rp,float wp)
{
    name = n ;
    brand = b ;
    available = a ;
    wnumber = wn ;
    sex = s ;
    retailprice = rp ;
    wholesaleprice = wp ;
}
product::product(const product &p)
{
    (*this) = p ;
}
float product::sell(int howmany)
{
    if (howmany > available)
    {
        cout << "There are only " << available << " products available." << endl ;
        return 0 ;
    }
    available = available - howmany ;
    if ( howmany < wnumber ) return (howmany*retailprice) ;
    else return (howmany*wholesaleprice) ;
}
float product::buy(int howmany , float p)
{
    available+=howmany ;
    return (howmany*p) ;
}
bool product::operator<(const product &p)
{
    if ((*this) == p) return true ;
    if ( brand < p.brand ) return true;
    if (brand == p.brand)
    {
        if ( name < p.name ) return true ;
    }
    return false ;
}

void product::operator=(const product &p)
{
    name = p.name ;
    brand = p.brand ;
    available = p.available ;
    wnumber = p.wnumber ;
    sex = p.sex ;
    retailprice = p.retailprice ;
    wholesaleprice = p.wholesaleprice ;

}
bool product::operator==(const product &p)
{
    if (brand == p.brand && name == p.name) return true ;
    else return false ;
}
void product::view()
{
     cout << brand << ' ' << name << endl ;
     cout << "Sex: " << sexnames[sex] << endl ;
     cout << "Retail price: " << retailprice << endl ;
     cout << "Wholesale price: " << wholesaleprice << endl ;
     cout << "In stock: " << available << endl ;
}

