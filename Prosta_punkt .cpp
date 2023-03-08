#include <iostream>
#include <stdexept>
using namespace std;

class Punkt
{
  double x,y;
public:
    Punkt(){
        this->x=1;
        this->y=2;
        };
    Punkt(double nx,double ny)
    {
        this->x=nx;
        this->y=ny;
    }
    int getX(){return this->x;};
    int getY(){return this->y;};
    void setX(int x1){this->x=x1;};
    void setY(int y1){this->y=y1;};
    void wypisz(){cout<<"wspolrzedna x to : "<<this->x<<" natomiast y to : "<<this->y<<endl;}
    friend ostream& operator<<(ostream&os,Punkt&P1);


};

ostream& operator<<(ostream&os,Punkt&P1)
 {
    os << "("<<P1.x<<","<<P1.y<<os << ")";
    //P1.wypisz();
    return os;
    };



class Prosta
{
private:
    double a,b;
public:
    Prosta(){this->a=1;this->b;};
    prosta(int a1,int b1)
    {
      this->a=a1;
      this->b=b1;

    };
    Prosta(Punkt P1,Punkt P2)
    {
      if(P1.getX()==P2.getX()){throw logic_error<<"blad"<<endl;}
      //(x-x2)(y1-y2)=(x1-x)(y1-y2);

    }
    double getA(){return this->a;};
    double getB(){return this->b;};
    void setA(int x1){this->a=x1;};
    void setB(int y1){this->b=y1;};
    //oid wypisz(){cout<<"x"endl;}


};


int main()
{
    Punkt p1(2,2);
    Punkt p2();
    p1.wypisz();
    p1.setX(11);
    p1.wypisz();
    cout<<p1.getX()-p1.getY()<<endl;
    //p2.wypisz();
    cout<<p1;
    Prosta (p1,p2);



}
