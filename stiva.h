#ifndef STIVA_H_INCLUDED
#define STIVA_H_INCLUDED
#include <iostream>
#include "pereche.h"
#include "multime.h"
using namespace std;

//stiva pereche
class stiva: public multime
{pereche top;


public:
//Constructor cu trimitere explicita
stiva():multime(){top=0;}
stiva(int n):multime(n){top=0;}
stiva(stiva &ob):multime(ob){top=ob.top;}
//operator >>/cin
friend istream& operator >>(istream& ,stiva &);
//operator <</cout
friend ostream& operator <<(ostream& ,const stiva&);
//adaugare in stiva
void push(pereche );
//stergere in stiva
pereche pop();
//verificare varf din stiva
pereche peek();
//operator =
stiva& operator =(const stiva &);
//golire stiva
void empty();
//Destructor
~stiva(){delete []p;
         top=0;
         n=0;}

};

#endif // STIVA_H_INCLUDED
