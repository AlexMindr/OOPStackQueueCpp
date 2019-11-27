#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED
#include <iostream>
#include "pereche.h"
#include "multime.h"
using namespace std;

//coada pereche
class coada: public multime
{pereche prim,ultim;

public:
//Constructor cu trimitere explicita
coada():multime(){prim=ultim=0;}
coada(int n):multime(n){prim=ultim=0;}
coada(coada &ob):multime(ob){prim=ob.prim;ultim=ob.ultim;}
//operator intrare cin//>>
friend istream& operator >>(istream&, coada&);
//operator iesire cout/<<
friend ostream& operator <<(ostream&, const coada&);
//operator =
coada& operator= (const coada&);
//adaugare element in coada
void push(pereche );
//eliminare element din coada
pereche pop();
pereche pop2();
//verificare care element este primul in coada
pereche peek();
//golire coada
void empty();
//verificare daca coada e goala
bool isempty()
{if(n>=1)return false;
return true;
}
//Destructor
~coada(){delete []p;
         prim=ultim=0;
         n=0;}
friend class stiva2cozi;
};


#endif // COADA_H_INCLUDED
