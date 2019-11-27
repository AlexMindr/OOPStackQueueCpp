#ifndef STIVA2COZI_H_INCLUDED
#define STIVA2COZI_H_INCLUDED
#include <iostream>
#include "pereche.h"
#include "multime.h"
#include "stiva.h"
#include "coada.h"
using namespace std;
//clasa pentru simulare operatii stiva cu 2 cozi
class stiva2cozi{
coada c1,c2;
public:
stiva2cozi(){coada c1,c2;
             this->c1=c1;
             this->c2=c2;}
friend ostream& operator <<(ostream&, const stiva2cozi&);
friend istream& operator >>(istream&, stiva2cozi&);
void push(pereche );
pereche pop();
~stiva2cozi(){};
};

#endif // STIVA2COZI_H_INCLUDED
