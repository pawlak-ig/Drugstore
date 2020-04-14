
#include "toothbrush.h"

toothbrush::toothbrush(const toothbrush &t)
{
    (product &)(*this) = (product &) t ;
    pieces = t.pieces ;
}

void toothbrush::operator=(const toothbrush &t)
{
    (product &)(*this) = (product &) t ;
    pieces = t.pieces ;
}
void toothbrush::view()
{
    product p(*this) ;
    p.view() ;
    cout << "Pieces: " << pieces << endl ;
}
