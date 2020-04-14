#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <iostream>
#include <string>
#define WNUM 50
using namespace std ;

class product {
    string name ;
    string brand ;
    int available, wnumber ;
    string sexnames[4] = { "man" , "woman" , "unisex" , "child" } ;
    enum {man,woman,unisex,child};
    int sex ;
    float retailprice , wholesaleprice ;
public :
    product() ;
    product(string n,string b,int a ,int wn, int s,float rp,float wp) ;
    product(char *n,char * b,int a ,int wn , int s,float rp,float wp) ;
    product(const product &) ;
    float sell( int ) ;
    float buy ( int , float p) ;
    bool operator<(const product &) ;
    bool operator>(const product &p) { if ((*this) < p || (*this) == p ) return false ; else return true;}
    bool operator<=(const product &p) {if ((*this) < p || (*this) == p ) return true ; else return false ;}
    bool operator>=(const product &p) {if(*this < p) return false ; else return true ;};
    bool operator==(const product &);
    bool operator != ( const product &p ) { if((*this) == p) return false ; else return true ; }
    virtual void operator=(const product &) ;
    virtual void view() ;
    virtual int cat() {return 0;} ;
    string brandd() {return brand ;} ;
    int av() { return available ;} ;
    virtual ~product() {} ;
    };

#endif // PRODUCT_H_INCLUDED
