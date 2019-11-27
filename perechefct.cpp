#include <iostream>
#include "pereche.h"
using namespace std;

istream& operator >>(istream& in,pereche &pr)
{   cout << "Introduceti elementul 1:";
    in >> pr.el1;
    cout << "Introduceti elementul 2:";
    in >> pr.el2;
return in;
}

ostream& operator <<(ostream &out, const pereche &pr)
{   out<<"("<<pr.el1<<","<<pr.el2<<")"<<" ";
    return out;
}

pereche& pereche::operator =(const pereche& ob)
{if(this==&ob)
return *this;
else {el1=ob.el1;
      el2=ob.el2;
     }
return *this;
}
