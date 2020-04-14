#include <iostream>
#include "shampoo.h"
#include <list>
#include "store.h"
#include "eyeliner.h"
#include "test.h"

enum type{moisturising,volumising,nutritiouning,antidandruff,repairing,smoothing};
enum sex{man,woman,unisex,child};
enum colour{black,blue,brown,purple,pink,glitery};
shampoo timo("Shampoo for men dry hair","Timotei",30,500,man,9.99,6.90,350,moisturising) ;
eyeliner lore("Extra-black eye liner","L'Oreal",100,50,woman,59.99,30.99,black) ;
showergel stimo("Vanilla shower gel","Timotei",40,60,unisex,7.99,4.96,500) ;
using namespace std;

int main()
{
    store S(10000) ;
    toothbrush tooth("Toothbrush Super Clean Set","Colgate",10,100,unisex,21.99,10.99,2) ;
    S.addnew(timo) ;
    S.addnew(lore) ;
    S.addnew(stimo) ;
    S.addnew(tooth) ;
    system(S) ;
}


