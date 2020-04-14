#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "store.h"
#include "eyeliner.h"
#include "showergel.h"
#include "shampoo.h"
#include "toothbrush.h"
#include <cstdio>



bool testproduct() ;
bool teststore() ;
void system(store SPP) ;
void dispbrand(store *SPP) ;
void disptype(store *SPP) ;
void addproduct(store *SPP) ;
bool correct(int,float,double,int,int) ;
inline void clean() { while (getc(stdin) != '\n') ; }
void withdrawproduct(store *SPP);
void sellproduct(store *SPP) ;
void buyproduct(store *SPP) ;
void addmoney(store *SPP) ;
void exampleuse() ;

#endif // TEST_H_INCLUDED
