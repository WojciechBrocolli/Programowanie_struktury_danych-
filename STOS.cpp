#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct Stos
{
private:
    int dltab;
    string*dane;
    int ilejest;
public:
    Stos(int rozmiar);
    ~Stos();
    void wypisz();
    void push(string s);
    bool isEmpty();
    string pop();
};

Stos::Stos(int rozmiar)
{
    if(rozmiar<=0)throw logic_error("Zla rozmiar");
    else
        dltab=rozmiar;
    ilejest=0;
    dane=new string[dltab];
}
Stos::~Stos()
{
    delete[]dane;
}

void Stos::wypisz()
{
    for(int i=0; i<ilejest; i++)
    {
        cout<<dane[i]<<" ";
    }
    cout<<endl;
}
void Stos::push(string s)
{
    if(ilejest<dltab)
    {
        dane[ilejest]=s;
        ilejest++;
    }
    else
    {
        throw logic_error("OJ JULEK JULEK");

    }
}
string Stos:: pop()
{
    if(ilejest<=0)
    {
        throw logic_error("OJ JULEK JULEK");
    }
    else
    {
        string k=dane[ilejest-1];
        ilejest--;
        return k;
    }
}

int main()
{
    string napis;
    char odp;
    Stos st(5);
    while(true)
    {
        cout<<"podaj slowo"<<endl;
        cin>>napis;
        try
        {
            st.push(napis);
            st.wypisz();
        }
        catch (exception&e)
        {
            cout<<e.what();
            break;
        }
        cout<<"czy wkladamy dalej T -tak ";
        cin>>odp;
        if(odp!='T'&&odp!='t')break;

    }
    cout<<endl<<st.pop()<<endl;
    return 0;

}
