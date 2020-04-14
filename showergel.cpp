#include "showergel.h"

showergel::showergel(const showergel &s)
{
    (product &)(*this) = (product &) s ;
    volume = s.volume ;
}

void showergel::operator=(const showergel &s)
{
    (product &)(*this) = (product &) s ;
    volume = s.volume ;
}
void showergel::view()
{
    product p(*this) ;
    p.view() ;
    cout << "Volume: " << volume << endl ;
}
