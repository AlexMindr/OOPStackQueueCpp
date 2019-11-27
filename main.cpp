#include <iostream>
#include "pereche.h"
#include "multime.h"
#include "coada.h"
#include "stiva.h"
#include "stiva2cozi.h"
using namespace std;

class citiren{
multime *v;
int nr;
public:
citiren(){nr=0;
           v=new multime[0];}
citiren(int n){v=new multime[n];
                nr=n;}
friend istream& operator >>(istream&, citiren&);
friend ostream& operator <<(ostream&, const citiren&);
~citiren(){delete[]v;
              nr=0;}
};

istream& operator>>(istream& in, citiren& ob)
{cout<<"Cate multimi de perechi doriti sa cititi?"<<endl;
    in>>ob.nr;
    delete []ob.v;
    ob.v=new multime[ob.nr];
  for(int i=0;i<ob.nr;i++)
  {cout<<"Multimea "<<i+1<<endl;
   in>>ob.v[i];}
  return in;
}
ostream& operator <<(ostream& out, const citiren& ob)
{out<<"Sunt "<<ob.nr<<" multimi de prechi"<<endl;
for(int i=0;i<ob.nr;i++)
    out<<"Multimea "<<i+1<<" este :"<<endl<<ob.v[i]<<endl;

    return out;
}

int main(){
    cout<<"Introduceti  nr care doriti sa-l vizualizati:"<<endl<< "1.clasa pereche"<<endl<<"2.clasa multime pereche"<<endl<<"3.clasa stiva pereche"<<endl<<"4.clasa coada pereche"<<endl<<"5.clasa care simuleaza stiva cu 2 cozi"<<endl<<"6.citire n multimi de perechi"<<endl<<"7.exit program"<<endl;
int com;
cin>>com;
while(com!=7&& com<7&& com>0){
switch(com){
case 1:
{
cout<<"Clasa pereche:"<<endl;
cout<<"Constructor fara parametru, perechea a este initializata cu 0:"<<endl;
pereche a;
cout<<a<<endl;
cout<<"Constructor cu un parametru, perechea b este un numar intreg si 0(de exemplu 2):"<<endl;
pereche b(2);
cout<<b<<endl;
cout<<"Constructor cu 2 parametri, perechea c este initializata cu 2 numere intregi de exemplu (1,3):"<<endl;
pereche c(1,3);
cout<<c<<endl;
cout<<"Apelare constructorul de copiere(de exemplu d va copia valoarea din perechea c):"<<endl;
pereche d(c);
cout<<d<<endl;
cout<<"Vrem sa vedem ce valoare are perechea c printr-un furnizor:"<<endl;
cout<<"-elementul 1:";
cout<<c.get_el1()<<endl;
cout<<"-elementul 2:";
cout<<c.get_el2()<<endl;
cout<<"Vrem sa setam valoarea din perechea c:"<<endl;
cout<<"-elementul 1 sa fie 2: ";
c.set_el1(2);
cout<<c<<endl;
cout<<"-elementul 2 sa fie 5: ";
c.set_el2(5);
cout<<c<<endl;
cout<<"Citirea unei perechi f de la tastatura si afisarea ei:"<<endl;
pereche f;
cin>>f;
cout<<f<<endl;
cout<<"Folosirea operatorului = pentru a da valoarea fractiei f lui g:"<<endl;
pereche g;
g=f;
cout<<g<<endl;
}
break;

case 2:
{cout<<"Clasa multime pereche:"<<endl;
cout<<"Constructor fara parametru, multimea m va avea 0 perechi:"<<endl;
multime m;
cout<<m;
cout<<"Constructor cu un parametru, multimea n va avea n perechi alocate, initializate cu 0 (exemplu 2 perechi):"<<endl;
multime n(2);
cout<<n;
cout<<"Citirea elementelor unei multimi m de perechi de la tastatura si afisarea ei:"<<endl;
cin>>m;
cout<<m;
cout<<"Apelare constructorul de copiere(de exemplu multimea o va copia multimea m):"<<endl;
multime o(m);
cout<<o;
cout<<"Vrem sa vedem ce numar de elemente are multimea m printr-un furnizor:"<<endl;
cout<<m.get_n()<<endl;
cout<<"Vrem sa vedem ce pereche se afla pe prima pozitie (pozitia x, particular x=0) in multimea m printr-un furnizor:"<<endl;
cout<<m.get_pi(0)<<endl;
cout<<"Vrem sa setam numarul de elemente din multimea p (exemplu 3 perechi):"<<endl;
multime p;
cout<<p;
p.set_n(3);
cout<<p;
cout<<"Vrem sa setam perechea 1 din multimea p (exemplu p[1]=(15,20)):"<<endl;
p.set_pi(1,15,20);
cout<<p;
cout<<"Folosirea operatorului = pentru a da valoarile din multimea m multimii q:"<<endl;
multime q;
cout<<q<<"devine"<<endl;;
q=m;
cout<<q;
cout<<endl;
cout<<"Tratare exceptii"<<endl;
cout<<"-cazul in care cand alocam un obiect ii dam memorie negativa"<<endl;
multime w(-1);
cout<<"-cazul in care cand alocam un obiect ii dam un string cand acesta nu contine string"<<endl;
multime y("Andrei");
}
break;

case 3:
{
cout<<"Clasa stiva pereche:"<<endl;
cout<<"Constructor fara parametru, stiva s va avea 0 perechi:"<<endl;
stiva s;
cout<<s;
cout<<"Constructor cu un parametru, stiva r va avea n perechi alocate, initializate cu 0 (exemplu 2 perechi):"<<endl;
stiva r(2);
cout<<r;
cout<<"Citirea elementelor unei stive s de perechi de la tastatura si afisarea ei:"<<endl;
cin>>s;
cout<<s;
cout<<"Apelare constructorul de copiere(de exemplu stiva s1 va copia stiva s):"<<endl;
stiva s1(s);
cout<<s1;
cout<<"Vrem sa vedem ce numar de elemente are stiva s printr-un furnizor:"<<endl;
cout<<s.get_n()<<endl;
cout<<"Vrem sa vedem ce pereche se afla in varful stivei s printr-o functie peek/furnizor:"<<endl;
cout<<s.peek()<<endl;
cout<<"Folosirea operatorului = pentru a da valoarile din stiva s stivei s2:"<<endl;
stiva  s2;
cout<<s2<<"devine"<<endl;
s2=s;
cout<<s2;
cout<<endl;

cout<<"Adaugare in stiva"<<endl;
stiva z;
cout<<"Stiva initiala este:" <<endl;
cout<<z;
cout<<"Cate elemente doriti sa adaugati ?"<<endl;
int nr;
pereche x;
cin>>nr;
for(int i=1;i<=nr;i++)
    {cout<<"Introduceti perechea "<<i<<" care sa fie adaugata:"<<endl;
    cin>>x;
    z.push(x);
    }
cout<<"Stiva dupa adaugare este:"<<endl;
cout<<z;
cout<<"Stergere din stiva"<<endl;
cout<<"Cate elemente doriti sa stergeti din stiva adaugata mai sus? (un nr <="<<nr<<" altfel va fi returnat -1"<<endl;
int kt;
cin>>kt;
for(int j=1;j<=kt;j++)
    z.pop();
cout<<"Stiva ramasa:"<<endl;
cout<<z;

cout<<"Stergerea intregii stive:"<<endl;
stiva st;
pereche ps1(1,2),ps2(3,4),ps3(5,6),ps4(7,8);

st.push(ps1);
st.push(ps2);
st.push(ps3);
st.push(ps4);
cout<<st;
cout<<"Dupa stergere completa devine:"<<endl;
st.empty();
cout<<st;
}
break;

case 4:
{cout<<"Clasa coada pereche:"<<endl;
cout<<"Constructor fara parametru, coada c1 va avea 0 perechi:";
coada c1;
cout<<c1;
cout<<"Constructor cu un parametru, coada c2 va avea n perechi alocate, initializate cu 0 (exemplu 2 perechi):"<<endl;
coada c2(2);
cout<<c2;
cout<<"Citirea elementelor unei coazi c1 de perechi de la tastatura si afisarea ei:"<<endl;
cin>>c1;
cout<<c1;
cout<<"Apelare constructorul de copiere(de exemplu coada c3 va copia coada c1):"<<endl;
coada c3(c1);
cout<<c3;
cout<<"Vrem sa vedem ce numar de elemente are coada c1 printr-un furnizor:"<<endl;
cout<<c1.get_n()<<endl;
cout<<"Vrem sa vedem ce pereche se afla prima in coada c1 printr-o functie peek/furnizor:"<<endl;
cout<<c1.peek()<<endl;
cout<<"Folosirea operatorului = pentru a da valoarile din coada c1 in coada c4:";
coada  c4;
cout<<c4<<"devine"<<endl;
c4=c1;
cout<<c4;
cout<<endl;


cout<<"Adaugare in coada"<<endl;
coada e;
cout<<"Coada initiala este:";
cout<<e;
cout<<"Cate elemente doriti sa adaugati ?"<<endl;
int nrc;
pereche xy;
cin>>nrc;
for(int i=1;i<=nrc;i++)
    {cout<<"Introduceti perechea "<<i<<" care sa fie adaugata:"<<endl;
    cin>>xy;
    e.push(xy);
    }
cout<<"Coada dupa adaugare este:"<<endl;
cout<<e;
cout<<"Stergere din coada"<<endl;
cout<<"Cate elemente doriti sa stergeti din coada adaugata mai sus? (un nr <="<<nrc<<" altfel va fi returnat -1"<<endl;
int ktc;
cin>>ktc;
for(int j=1;j<=ktc;j++)
    e.pop();
cout<<"Coada ramasa:"<<endl;
cout<<e;

cout<<"Stergerea intregii cozi:"<<endl;
coada j;

pereche ps1(1,2),ps2(3,4),ps3(5,6),ps4(7,8);
j.push(ps1);
j.push(ps2);
j.push(ps3);
j.push(ps4);
cout<<j;
cout<<"Dupa stergere completa devine:";
j.empty();
cout<<j;
}
break;

case 5:
 {cout<<"Simularea operatiilor la nivelul stivei pereche cu 2 cozi pereche"<<endl;
cout<<"Constructorul care initializeaza coazile pereche cu 0(vide):"<<endl;
stiva2cozi ab;
cout<<ab;
cout<<"Citirea perechilor care vor fi prelucrate la operatii(mai mult de 2)"<<endl;
cin>>ab;
cout<<"Afisarea acestor date prelucrate:"<<endl;
cout<<ab;
cout<<"Functia de adaugare pereche pentru simulare, de exemplu vom adauga (1,2) (3,4) (5,6) (7,8):"<<endl;
stiva2cozi h;
cout<<"La inceput este:"<<endl;
cout<<h;
cout<<"Dupa adaugare este:"<<endl;

pereche ps1(1,2),ps2(3,4),ps3(5,6),ps4(7,8);
h.push(ps1);
h.push(ps2);
h.push(ps3);
h.push(ps4);
cout<<h;
cout<<"Stergerea elementelor din aceasta stiva simulata + afisare, la final stergere cand este goala:"<<endl;
h.pop();
h.pop();
h.pop();
h.pop();
cout<<h;
h.pop();
 }
break;

case 6:
{
cout<<endl;
cout<<"Citirea a n multimi de perechi"<<endl;
citiren obj;
cin>>obj;
cout<<obj;
}
break;
}
cout<<"Ce mai doriti sa vizualizati? :"<<endl<< "1.clasa pereche"<<endl<<"2.clasa multime pereche"<<endl<<"3.clasa stiva pereche"<<endl<<"4.clasa coada pereche"<<endl<<"5.clasa care simuleaza stiva cu 2 cozi"<<endl<<"6.citire n multimi de perechi"<<endl<<"7.exit program"<<endl;
cin>>com;
}

    return 0;
}
