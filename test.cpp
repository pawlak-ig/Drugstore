#include "test.h"
#include <iomanip>
#include <cstdio>
enum type{moisturising,volumising,nutritiouning,antidandruff,repairing,smoothing};
enum sex{man,woman,unisex,child};
enum colour{black,blue,brown,purple,pink,glitery};
string ex("Incorrect input, try again") ;



store SP(10000) ;
shampoo tim("Shampoo for men dry hair","Timotei",30,500,man,9.99,6.90,350,moisturising) ;
shampoo identical(tim) ;
eyeliner lor("Extra-black eye liner","L'Oreal",100,50,woman,59.99,30.99,black) ;
showergel stim("Vanilla shower gel","Timotei",40,60,unisex,7.99,4.96,500) ;

bool testproduct()
{
    product p(tim) ;
    if ( p.buy(10,8) != 80 || p.av() != 40 ) return false ;
    if ( (p.sell(10) != 99.9 ) || p.av() != 30 ) return false ;
    if ( tim != identical || !(tim == identical) ) return false ;
    if (tim < identical || tim > identical) return false ;
    if (!(tim <= identical) || !(tim >= identical)) return false ;
    cout << "Class 'Product' works properly" << endl ;
    return true ;
}

bool teststore()
{
    SP.addnew(tim) ;
    if ( SP.seek(tim) == nullptr ) return false ;
    if ( SP.buy(tim,100,3.99) == false || SP.mon() != (10000 - 399) || (SP.seek(tim))->av() != 130 ) return false ;
    SP.addnew(stim);
    if ( SP.sell(stim,30) == false || SP.mon() != (9601+7.99*30) || (SP.seek(stim))->av() != 10  ) return false ;
    SP.addnew(lor) ;
    if(SP.sell(lor,60) == false || SP.mon() != 11700.1 || (SP.seek(lor))->av() != 40) return false ;
    if ( SP.withdraw(tim) == false || SP.seek(tim) != nullptr ) return false ;
    cout << "Class 'Store' works properly" << endl ;
    return true ;
}
void system(store SPP)
{
    int choice = 0 ;
    cout << setw(65) << "Super-Pharm Store Managing System" << endl ;
    while (choice != 9 )
    {
        cout << setw(50) << "MENU" << endl ;
        cout << "1 - display all products\n2 - display brand\n3 - display type\n4 - add new product\n5 - withdraw a product\n" ;
        cout << "6 - sell a product\n7 - buy product\n8 - add more money\n9 - end" << endl ;
        cin >> choice ;
        switch ( choice )
        {
            case 1 : SPP.viewall() ;
            break ;
            case 2 : dispbrand(&SPP) ;
            break ;
            case 3 : disptype(&SPP) ;
            break ;
            case 4: addproduct(&SPP) ;
            break ;
            case 5: withdrawproduct(&SPP) ;
            break ;
            case 6: sellproduct(&SPP) ;
            break ;
            case 7: buyproduct(&SPP) ;
            break ;
            case 8: addmoney(&SPP) ;
            break ;
            default: break ;
        }


}
}
void dispbrand(store *SPP)
{
    string b ;
    clean() ;
    cout << "Enter the name of the brand" << endl ;
    getline(cin,b) ;
    SPP->viewbrand(b) ;
}
void disptype(store *SPP)
{
    int i ;
    cout << "Choose type of product" << endl ;
    cout << "0 - shampoos\n1 - shower gels\n2 - eyeliners\n3 - toothbrushes\n" ;
    cin >> i ;
     while ( cin.fail() || !correct(i,1,1,1,1) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> i;
    }
    SPP->viewcategory(i) ;
}
void addproduct(store *SPP)
{
    string b , n ;
    int av , wn , s , c ,t ,col;
    float rp , wp ;
    double v ;
    cout << "Choose type of product" << endl ;
    cout << "0 - shampoos\n1 - shower gels\n2 - eyeliners\n3 - toothbrushes\n" ;
    cin >> c ;
    while ( cin.fail() || !correct(c,1,1,1,1) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> c;
    }
    clean() ;
    cout << "Name of the brand:\n" ;
    getline(cin,b) ;
    cout << "Name of the product:" << endl ;
    getline(cin,n) ;
    cout << "Currently available:" << endl ;
    cin >> av ;
    while (cin.fail() ||  !correct(1,1,1,1,av) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> av ;
    }
    clean() ;
    cout << "How many to make wholesale?" << endl ;
    cin >> wn ;
    while ( cin.fail() || !correct(1,1,1,1,wn) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> wn ;
    }
    clean() ;
    cout << "Sex: 0 - man\t1 - woman\t2 - unisex\t3 - child" << endl ;
    cin >> s ;
    while ( cin.fail() || !correct(s,1,1,1,1) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> s;
    }
    clean() ;
    cout << "Retailprice: " << endl ;
    cin >> rp ;
    while ( cin.fail() || !correct(1,rp,1,1,1))
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> rp ;
    }
    clean() ;
    cout << "Wholesaleprice: " << endl ;
    cin >> wp ;
    while (cin.fail() ||  !correct(1,wp,1,1,1) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> wp ;
    }
    if ( c == 0 )
    {
        cout << "Volume: " << endl ;
        cin >> v ;
        while ( cin.fail() || !correct(1,1,v,1,1) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> v ;
    }
        cout << "Choose type:\n0 - moisturising\t\t1 - volumising\n" ;
        cout << "2 - nutritiouning\t\t3 - antidandruff\n" ;
        cout << "4 - repairing\t\t\t5 - smoothing" << endl ;
        cin >> t ;
         while ( cin.fail() || !correct(t,1,1,2,1) )
        {
            cin.clear();
            cin.ignore( 1000, '\n');
            cout << ex << endl;
            cin >> t ;
        }
            shampoo shh(n,b,av,wn,s,rp,wp,v,t) ;
            SPP->addnew(shh) ;
            cout << "Added successfully" << endl ;

    }
    if ( c == 1 )
    {
        cout << "Volume (ml): " << endl ;
        cin >> v ;
        while ( cin.fail() ||  !correct(1,1,v,1,1) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> v ;
    }
            showergel sh ( n,b,av,wn,s,rp,wp,v ) ;
            SPP->addnew(sh) ;
    }
    if ( c == 2 )
    {
        cout << "Choose colour\n0 -  black\t1 - blue\t2 - brown\n3 - purple\t4 - pink\t5 - glittery" << endl ;
        cin >> col ;
        while ( cin.fail() || !correct(col,1,1,2,1) )
        {
            cin.clear();
            cin.ignore( 1000, '\n');
            cout << ex << endl;
            cin >> col ;
        }
            eyeliner e(n,b,av,wn,s,rp,wp,col) ;
            SPP->addnew(e) ;
    }
    if (c == 3)
    {
        cout << "How many pieces?" << endl ;
        cin >> col ;
        while ( cin.fail() || col > 0)
        {
            cin.clear();
            cin.ignore( 1000, '\n');
            cout << ex << endl;
            cin >> col ;
        }
    }

}
void withdrawproduct(store *SPP)
{
    string b,n ;
    clean() ;
    cout << "Name of the brand:\n" ;
    getline(cin,b) ;
    cout << "Name of the product:" << endl ;
    getline(cin,n) ;
    product p( n,b,0,0,0,0,0 ) ;
    if (!SPP->withdraw(p) )
    {
        cout << "There is no such product,try again" << endl ;
        return ;
    }

}
void sellproduct(store *SPP)
{
    string b,n ;
    int h ;
    clean() ;
    cout << "Name of the brand:\n" ;
    getline(cin,b) ;
    cout << "Name of the product:" << endl ;
    getline(cin,n) ;
    product p (n,b,0,0,0,0,0) ;
    cout << "How many?" << endl ;
    cin >> h ;
    while (cin.fail() ||  !correct(1,1,1,1,h) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> h ;
    }
    if ( !SPP->sell(p,h))
    {
        cout << "There is no such product or not enough of it, try again" << endl ;
        return ;
    }
}
void buyproduct(store *SPP)
{
    string b,n ;
    int h ;
    float pr ;
    clean() ;
    cout << "Name of the brand:\n" ;
    getline(cin,b) ;
    cout << "Name of the product:" << endl ;
    getline(cin,n) ;
    cout << "How many?" << endl ;
    cin >> h ;
    product p(n,b,0,0,0,0,0) ;
    while (cin.fail() ||  !correct(1,1,1,1,h) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> h ;
    }
    clean() ;
    cout << "At what price?" << endl ;
    cin >> pr ;
    while (cin.fail() ||  !correct(1,pr,1,1,1) )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> pr ;
    }
    if (!SPP->buy(p,h,pr))
    {
        cout << "There is no such product or not enough money" << endl ;
    }
    cout << "You have " << SPP->mon() << " zl left." << endl ;

}
void addmoney(store *SPP)
{
    float f ;
    cout << "Enter the amount of money" << endl ;
    cin >> f ;
    while (cin.fail() )
    {
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << ex << endl;
        cin >> f ;
    }
    SPP->addmoney(f) ;
}
void exampleuse()
{
    store S ;
    cout << "Adding products to the store." << endl ;
    S.addnew(tim) ;
    S.addnew(lor) ;
    S.addnew(stim) ;
    cout << "Viewing products." << endl ;
    S.viewall() ;
    cout << "Selling 10 L'oreal eyeliners." << endl ;
    S.sell(lor,10) ;
    cout << "There is " << S.mon() << " zl in the store." << endl ;
    cout << "Buying 100 Timotei shampoos at 5zl" << endl ;
    if (!S.buy(tim,100,5)) cout << "Ops, there is not enough money" << endl ;
    cout << "Withdrawing Timotei shampoo" << endl ;
    S.withdraw(tim) ;
    cout << "Left in the store: " << endl ;
    S.viewall() ;
    cout << "Available eyeliners: " << endl ;
    S.viewcategory(2) ;


}
bool correct(int i,float f,double d,int w,int a)
{
    if (f <= 0 || d <= 0 ) return false;
    if (w == 1)
    {
        if ( i < 0 || i > 3) return false ;
    } else if (i < 0 || i > 5) return false ;
    if (a < 0) return false ;
    return true ;
}
