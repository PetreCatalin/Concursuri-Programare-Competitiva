#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int rep=1,x,nr1,nr2,nr3;

class client
{
    protected:
    char nume[100];
    char oras[100];
    int numar;
    int varsta;
    int sold;
    char data[100];
    public:
    char * get_data() {return data;}
};

class contcurent: public client
{
    int nrtrgr;
    friend istream &operator >> (istream & in,contcurent &a)
    {
        cout<<"numar:\n";
        in>>a.numar;
        in.get();
        cout<<"nume\n";
        gets(a.nume);
        cout<<"varsta\n";
        in>>a.varsta;
        cout<<"oras\n";
        in>>a.oras;
        cout<<"sold\n";
        in>>a.sold;
        cout<<"data\n";
        in>>a.data;
        cout<<"tranzactii gratuite\n";
        in>>a.nrtrgr;
        return in;
    }
    friend ostream &operator <<(ostream &out,contcurent &a)
    {
        out<<"Nr. ";
        out<<a.numar;
        out<<','<<a.nume;
        out<<','<<a.varsta;
        out<<','<<a.oras;
        out<<','<<a.data;
        out<<",Tranzactii gratuite: ";
        out<<a.nrtrgr;
        out<<"Sold: ";
        out<<','<<a.sold;
        return out;
    }
}cc[100];

class conteconomii :public client
{
    int dobanda;
     friend istream &operator >> (istream & in,conteconomii &a)
    {
        cout<<"numar:\n";
        in>>a.numar;
        in.get();
        cout<<"nume\n";
        gets(a.nume);
        cout<<"varsta\n";
        in>>a.varsta;
        cout<<"oras\n";
        in>>a.oras;
        cout<<"sold\n";
        in>>a.sold;
        cout<<"data\n";
        in>>a.data;
        cout<<"dobanda\n";
        in>>a.dobanda;
        return in;
    }
    friend ostream &operator <<(ostream &out,conteconomii &a)
    {
        out<<"Nr. ";
        out<<a.numar;
        out<<','<<a.nume;
        out<<','<<a.varsta;
        out<<','<<a.oras;
        out<<','<<a.data;
        out<<",Dobanda: ";
        out<<a.dobanda<<"% ";
        out<<"Sold: ";
        out<<','<<a.sold;
        return out;
    }
}ce[100];

class depozitlatermen :public client
{
    int dobanda;
    int termen;
     friend istream &operator >> (istream & in,depozitlatermen &a)
    {
        cout<<"numar:\n";
        in>>a.numar;
        in.get();
        cout<<"nume\n";
        gets(a.nume);
        cout<<"varsta\n";
        in>>a.varsta;
        cout<<"oras\n";
        in>>a.oras;
        cout<<"sold\n";
        in>>a.sold;
        cout<<"data\n";
        in>>a.data;
        cout<<"dobanda\n";
        in>>a.dobanda;
        cout<<"termen\n";
        in>>a.termen;
        return in;
    }
     friend ostream &operator <<(ostream &out,depozitlatermen &a)
    {
        out<<"Nr. ";
        out<<a.numar;
        out<<','<<a.nume;
        out<<','<<a.varsta;
        out<<','<<a.oras;
        out<<','<<a.data;
        out<<",Dobanda: ";
        out<<a.dobanda<<"% ";
        out<<",Termen ";
        if (a.termen==1) out<<a.termen<<" an";
        else
        out<<a.termen<<" luni";
        out<<"Sold: ";
        out<<','<<a.sold;
        return out;
    }
}dt[100];

void afis1()
{
    int i;
    for (i=1;i<=nr1;++i)
        cout<<cc[i]<<"\n";
    for (i=1;i<=nr2;++i)
        cout<<ce[i]<<"\n";
    for (i=1;i<=nr3;++i)
        cout<<dt[i]<<"\n";

    cout<<"\n";
}

void afis3()
{
    int i,an,nr;
    for (i=1;i<=nr1;++i)
        {
            nr=strlen(cc[i].get_data())-1;
            an=(cc[i].get_data()[nr-3]-'0')*1000+(cc[i].get_data()[nr-2]-'0')*100+(cc[i].get_data()[nr-1]-'0')*10+(cc[i].get_data()[nr]-'0');
            if (an==2013) cout<<cc[i];
        }
         for (i=1;i<=nr2;++i)
        {
            nr=strlen(ce[i].get_data())-1;
            an=(ce[i].get_data()[nr-3]-'0')*1000+(ce[i].get_data()[nr-2]-'0')*100+(ce[i].get_data()[nr-1]-'0')*10+(ce[i].get_data()[nr]-'0');
            if (an==2013) cout<<ce[i];
        }
         for (i=1;i<=nr3;++i)
        {
            nr=strlen(dt[i].get_data())-1;
            an=(dt[i].get_data()[nr-3]-'0')*1000+(dt[i].get_data()[nr-2]-'0')*100+(dt[i].get_data()[nr-1]-'0')*10+(dt[i].get_data()[nr]-'0');
            if (an==2013) cout<<dt[i];
        }

        cout<<"\n";
}

void meniu()
{
    cout<<"1.Persoana cu cont curent\n";
    cout<<"2.Persoana cu cont economii\n";
    cout<<"3.Persoana cu depozitlatermen\n";
    cout<<"4.afis1\n";
    cout<<"5.afis3\n";
    cout<<"6.afis4\n";
    cout<<"7.inchidere meniu\n";
}

int main()
{
    meniu();
    while (rep==1) {
            cout<<"Introduceti optiunea dorita\n";
            cin>>x;
            if (x==1) {
                ++nr1;
                cin>>cc[nr1];
            }
            if (x==2) {
                ++nr2;
                cin>>ce[nr2];
            }
            if (x==3) {
                ++nr3;
                cin>>dt[nr3];
            }
            if (x==4) afis1();
            if (x==5) afis3();
            if (x==7) {
                    rep=0;
                    return 0;
            }
    }
    return 0;
}
