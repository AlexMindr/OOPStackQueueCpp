#ifndef PERECHE
#define PERECHE
#include <iostream>

using namespace std;
class pereche
{int el1,el2;
public:
//setat
void set_el1(int el1){this->el1=el1;}
void set_el2(int el2){this->el2=el2;}
//furnizat
int get_el1(){return el1;}
int get_el2(){return el2;}
//constructor
pereche(){el1=0;el2=0;}
pereche(int el1){
this->el1=el1;
this->el2=0;
}
pereche(int el1,int el2)
{this->el1=el1;
this->el2=el2;
}
//copy constructor
pereche (const pereche &ob)
{el1=ob.el1;
el2=ob.el2;
}

//citire cin>>/operator>>
friend istream& operator >>(istream&,pereche&);
//afisare cout<</operator<<
friend ostream& operator <<(ostream&, const pereche&);
//operator =
pereche& operator =(const pereche&);
//destructor
~pereche(){}//cout<<"Destructor"}
friend class multime;
};

#endif // PERECHE
