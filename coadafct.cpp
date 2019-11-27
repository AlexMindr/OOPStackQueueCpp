#include <iostream>

#include "pereche.h"
#include "multime.h"
#include "coada.h"
using namespace std;

istream& operator >>(istream& in, coada &ob)
{cout<<"Introduceti numarul de elemente din coada:"<<endl;
in>>ob.n;
delete []ob.p;
ob.p=new pereche[ob.n];
    for(int i=0;i<ob.n;i++)
    {cout << "Introducet perechea "<<i+1<<" din coada: "<<endl;
    in >> ob.p[i];
    }
    ob.ultim=ob.p[ob.n-1];
    ob.prim=ob.p[0];
    return in;
}

ostream& operator <<(ostream& out,const coada &ob)
{if(ob.n)out<<"Sunt "<<ob.n<<" perechi in acesta coada"<<endl;
    for(int i=0;i<ob.n;i++)
      out<<ob.p[i];
      if(ob.n)out<<endl;
    if(ob.n)out<<"Front-ul acestei cozi este: "<<ob.prim<<endl<<"Rear-ul acestei cozi este: "<<ob.ultim<<endl;
    else out<<"Coada vida!"<<endl;
    return out;
}

coada& coada::operator =(const coada& ob)
{if(this==&ob)
return *this;
else {delete []p;
      n=ob.n;
      p=new pereche[n];
      for (int i=0;i<n;i++)
      p[i]=ob.p[i];
      prim=ob.prim;
      ultim=ob.ultim;
     }
return *this;
}

void coada::push(pereche x)
{if(n==0){n=1;
p=new pereche[n];
p[0]=x;
prim=ultim=x;
}
else {this->renew(1);

p[n-1]=x;
ultim=x;}

}

pereche coada::pop()
{
pereche auxi;
    if(n){auxi=prim;
    for(int j=1;j<n;j++)
        p[j-1]=p[j];
    p[n-1]=prim;
    ultim=p[n-2];
    prim=p[0];
    this->renew(-1);
    cout<<"Perechea "<<auxi<<" a fost eliminata"<<endl;
    return auxi;}
    else {cout<<"Coada este vida, va fi returnat -1!"<<endl;
            return -1;}
}
pereche coada::pop2()
{pereche auxi;
    if(n){auxi=prim;
    for(int j=1;j<n;j++)
        p[j-1]=p[j];
    p[n-1]=prim;
    ultim=p[n-2];
    prim=p[0];
    this->renew(-1);
    return auxi;}
    else {cout<<"Coada este vida, va fi returnat -1!"<<endl;
            return -1;}
}

pereche coada::peek(){if (n)return prim;
                      else {cout<<"Coada este vida, va fi returnat -1!"<<endl;
                           return -1;}}

void coada::empty(){
while(n)
    this->pop();
}
