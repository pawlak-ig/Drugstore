#include "shampoo.h"

shampoo::shampoo(const shampoo &s)
{
    (product &)(*this) = (product &) s ;
    volume = s.volume ;
    type = s.type ;
}

void shampoo::operator=(const shampoo &s)
{
    (product &)(*this) = (product &) s ;
    volume = s.volume ;
    type = s.type ;
}
void shampoo::view()
{
    product p(*this) ;
    p.view() ;
    cout << "Volume: " << volume << " ml" << endl ;
    cout<< "Type: " << typenames[type] << endl;
}

