#include "eyeliner.h"

eyeliner::eyeliner(const eyeliner &e)
{
    (product &)(*this) = (product &) e ;
    colour = e.colour ;
}

void eyeliner::operator=(const eyeliner &e)
{
    (product &)(*this) = (product &) e ;
    colour = e.colour ;
}
void eyeliner::view()
{
    product p(*this) ;
    p.view() ;
    cout<< "Colour: " << colournames[colour] << endl;
}
