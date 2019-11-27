#include <iostream>
#include "pereche.h"
#include "multime.h"
#include "stiva.h"
using namespace std;
istream& operator >>(istream& in,stiva& ob)
{cout<<"Introduceti numarul de elemente din stiva:"<<endl;
in>>ob.n;
delete []ob.p;
ob.p=new pereche[ob.n];
    for(int i=0;i<ob.n;i++)
    {cout << "Introducet perechea "<<i+1<<" din stiva: "<<endl;
    in >> ob.p[i];
    }
    ob.top=ob.p[ob.n-1];
    return in;
}

ostream& operator <<(ostream &out, const stiva &ob)
{
    if(ob.n)out<<"Sunt "<<ob.n<<" perechi in acesta stiva"<<endl;
    for(int i=ob.n-1;i>=0;i--)
      out<<ob.p[i]<<endl;
    if(ob.n)out<<"Top-ul acestei stive este: "<<ob.top<<endl;
    else out<<"Stiva vida!"<<endl;
    return out;
}

stiva& stiva::operator =(const stiva& ob)
{if(this==&ob)
return *this;
else {delete []p;
      n=ob.n;
      p=new pereche[n];
      for (int i=0;i<n;i++)
      p[i]=ob.p[i];
      top=ob.top;
     }
return *this;
}

void stiva::push(pereche x){
if(n==0){n=1;
this->p=new pereche[n];
p[0]=x;
top=x;
}
else {renew(1);
p[n-1]=x;
top=x;}
}

pereche stiva::pop(){
    if(n){pereche auxi;
    auxi=top;
    this->renew(-1);
    top=p[n-1];
    cout<<"Perechea "<<auxi<<" a fost eliminata"<<endl;
    return auxi;}
    else {cout<<"Stiva este vida, va fi returnat -1!"<<endl;
            return -1;}
}

pereche stiva::peek(){if (n)return top;
                      else {cout<<"Stiva este vida, va fi returnat -1!"<<endl;
                           return -1;}}

void stiva::empty(){
while(n)
    this->pop();
}
