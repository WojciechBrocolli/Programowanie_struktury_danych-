#ifndef yolo
#define yolo
#include <iostream>
#include <stdexcept>
using namespace std;
struct Kolejka
{
private:
    int *dane;
    int ileJest;
public:
    Kolejka();
    ~Kolejka();
    void wstaw (int A);
    void wypisz();
    int usun();


};

Kolejka ::Kolejka()
{
    ileJest=0;
    dane=nullptr;
}
Kolejka::~Kolejka()
{

    if(ileJest>0)
        delete []dane;
}
void Kolejka::wstaw (int A)
{
    int *pom=new int [ileJest+1];
    //int *pom[ileJest+1];
    for(int i=0;i<ileJest;i++)
    {
        pom[i]=dane[i];
    }
    pom[ileJest]=A;
    delete[]dane;
    dane=pom;
    ileJest++;
}
void Kolejka::wypisz()
{
    if(ileJest<=0) cout<<"logical error"<<endl;
    else{
    for(int i=0;i<ileJest;i++)
    {
        cout<<dane[i];
    }
    }

}
int Kolejka::usun()
{
    if(ileJest<=0)throw logic_error("logical error");
    int temp;
    int *pom=new int [ileJest-1];
    //int *pom[ileJest+1];
    for(int i=0;i<ileJest;i++)
    {
        pom[i]=dane[i+1];
    }
    temp=dane[0];
    delete[]dane;
    dane=pom;
    ileJest--;
    return temp;
}



#endif // yolo



#include <iostream>
#include "KOLEJKA.H"
using namespace std;

int main()
{
    Kolejka Poliwczak;
    Poliwczak.wypisz();
    Poliwczak.wstaw(7);
    Poliwczak.wstaw(5);
    Poliwczak.wstaw(1);
    Poliwczak.wstaw(3);
    Poliwczak.wstaw(2);
    Poliwczak.wypisz();
    cout<<endl;
    try{
    Poliwczak.wstaw(Poliwczak.usun());
    catch(exception &e);
    }
    Poliwczak.wypisz();
}
