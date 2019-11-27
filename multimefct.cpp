#include <iostream>
#include "pereche.h"
#include "multime.h"
using namespace std;

multime& multime::operator =(const multime& ob)
{if(this==&ob)
return *this;
else {delete []this->p;
      this->n=ob.n;
      p=new pereche[ob.n];
      for (int i=0;i<ob.n;i++)
      p[i]=ob.p[i];
     }
return *this;
}

istream& operator >>(istream& in,multime& ob)
{   cout << "Introduceti n:";
    in>>ob.n;
    delete []ob.p;
    ob.p=new pereche[ob.n];
    for(int i=0;i<ob.n;i++)
    {cout << "Introducet perechea "<<i+1<<" : "<<endl;
    in >> ob.p[i];
    }
return in;
}

ostream& operator <<(ostream &out, const multime &ob)
{
    out<<"Sunt "<<ob.n<<" perechi in acest obiect"<<endl;
    for(int i=0;i<ob.n;i++)
      out<<"Perechea "<<i+1<<" este: "<<ob.p[i]<<endl;
    return out;
}

void multime::renew(int x)
{
pereche a[this->n+x];
for(int i=0;i<n;++i)
    a[i]=p[i];
n=n+x;
delete []p;
p=new pereche[n];
for(int i=0;i<n;i++)
    p[i]=a[i];

}
