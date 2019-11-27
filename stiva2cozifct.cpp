#include <iostream>
#include "pereche.h"
#include "multime.h"
#include "stiva.h"
#include "coada.h"
#include "stiva2cozi.h"
using namespace std;



istream& operator >>(istream& in, stiva2cozi& ob)
{cout<<"Introduceti numarul de perechi cu care se va lucra:"<<endl;
            int nr;
            in>>nr;
            pereche x;
            if(nr>1){
            for(int i=1;i<=nr;i++)
            {cout<<"Introduceti perechea: "<<i<<endl;
             in>>x;
             ob.push(x);}
            }
            else if(nr==1){cout<<"Trebuie lucrat cu mai mult de o pereche, reintroduceti nr"<<endl;
                           in>>nr;
                            for(int i=1;i<=nr;i++)
                            {cout<<"Introduceti perechea: "<<i<<endl;
                                in>>x;
                                ob.push(x);}}
      return in;
}

ostream& operator <<(ostream& out,const stiva2cozi& ob)
{out<<"Stiva finala (sub forma de coada) este:"<<endl;
out<<ob.c1;

return out;
}

void stiva2cozi::push(pereche x)
{c2.push(x);

while (c1.n)
    {
      c2.push(c1.pop2());
     }

coada ca;
c1=c2;
c2=ca;

}

pereche stiva2cozi::pop(){
    return c1.pop();
}
