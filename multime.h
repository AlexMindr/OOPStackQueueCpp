#ifndef MULTIME_H_INCLUDED
#define MULTIME_H_INCLUDED
#include <iostream>
#include "pereche.h"

using namespace std;


//clasa multime pereche
class multime{
protected:
int n;
pereche *p;
public:
//setter
void set_n(int n){this->n=n;
                  p=new pereche[n];
                    for(int i=0;i<n;++i)
                        p[i]=0;}

void set_pi(int i,int el1,int el2){if (i<0||i>=n) return ;
                                    else if (n!=0){this->p[i].el1=el1;
                                                this->p[i].el2=el2;}
                                        else return ;
                                  }
//getter
int get_n(){return n;}
pereche get_pi(int i){return p[i];}
//constructor
multime(){this->n=0;
         p=new pereche[0];}
multime(int n){if(n>=0){this->n=n;
                        p=new pereche[n];
                        for(int i=0;i<n;++i)
                        p[i]=0;
                        }
                else {//exceptie alocare de memorie un numar negativ
                        if(n<0){try
                                    {
                                if (n<0) throw n;
                                    }
                                    catch(int x)
                                    {
                                    cout<<"Exceptie gasita, alocare numar negativ!"<<"\n";
                                    }
                                }
                     cout<<"Numarul care a-ti incercat sa il alocati este: "<<n<<endl;
                     }
              }
multime (const multime &ob)
{n=ob.n;
p=new pereche[n];
for (int i=0;i<n;i++)
    p[i]=ob.p[i];}
//exceptie alocare memorie un string in loc de int
multime (string a){
try {
    throw a;
    }
 catch(string y)
 {
 cout<<"Exceptie gasita, alocare sir de caractere in loc de int!"<<"\n";
 }
}
//citire cin>>/operator>>
friend istream& operator >>(istream&,multime&);
//afisare cout<</operator<<
friend ostream& operator <<(ostream&, const multime&);
//operator =
multime& operator =(const multime&);
//destructor
virtual ~multime(){delete []p;
                   n=0;}
void renew (int);

};

#endif // MULTIME_H_INCLUDED
