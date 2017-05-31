#include <iostream>

using namespace std;

int rep=0,x,nra=0,nrc=0,nrp=0;

class ft{
    protected:
    char titlu[100];
    int an;
    struct structura {
        char nume[100];
        char prenume[100];
    }autor[100];
        public:
        int get_an() {return an;}
};

class articol:public ft
{
    char n[100];
    int numar,numar1,numar2,nr;
    public:
    friend istream & operator >> (istream &in,articol &a)
    {
        cout<<"Introduceti numarul de autori:\n";
        in>>a.nr;
        for (int i=1;i<=a.nr;++i) {
            cout<<"Introduceti numele:\n";
            in>>a.autor[i].nume;
            cout<<"Introduceti prenumele:\n";
            in>>a.autor[i].prenume;
        }
        cout<<"Introduceti titlul articolului\n";
        in>>a.titlu;
        cout<<"Introduceti anul publicarii\n";
        in>>a.an;
        cout<<"Numele revistei\n";
        in>>a.n;
        cout<<"Numarul revistei\n";
        in>>a.numar;
        cout<<"Numerele paginilor\n";
        in>>a.numar1>>a.numar2;
        return in;
    }
    friend ostream & operator <<(ostream &out,articol &a)
    {
        int i;
        for (i=1;i<=a.nr;++i)
            out<<a.autor[i].nume<<' '<<a.autor[i].prenume<<' ';
        out<<a.titlu<<' '<<a.an<<' '<<a.n<<' '<<a.numar<<' '<<a.numar1<<'-'<<a.numar2;
        return out;
    }
    int get_nr() {return nr;}
} art[100];

class carte:public ft
{
    char ne[100],oe[100];
    int nr;
    public:
    friend istream &operator >> (istream &in,carte &c)
    {
        cout<<"Introduceti numarul de autori:\n";
        in>>c.nr;
        for (int i=1;i<=c.nr;++i) {
            cout<<"Introduceti numele:\n";
            in>>c.autor[i].nume;
            cout<<"Introduceti prenumele:\n";
            in>>c.autor[i].prenume;
        }
        cout<<"Introduceti titlul cartii\n";
        in>>c.titlu;
        cout<<"Introduceti anul publicarii\n";
        in>>c.an;
        cout<<"Numele editurii\n";
        in>>c.ne;
        cout<<"Orasul editurii\n";
        in>>c.oe;
        return in;
    }
    friend ostream & operator <<(ostream &out,carte &a)
    {
        int i;
        for (i=1;i<=a.nr;++i)
            out<<a.autor[i].nume<<' '<<a.autor[i].prenume<<' ';
        out<<a.titlu<<' '<<a.an<<' '<<a.ne<<' '<<a.oe;
        return out;
    }
    int get_nr(){return nr;}
}cart[100];

class fe{
    char nume[100];
    char titlu[100];
    char url[100];
    char data[100];
    public:
    friend istream &operator >> (istream &in,fe &x)
    {
        cout<<"Numele proprietarului:\n";
        in>>x.nume;
        cout<<"Titlul paginii:\n";
        in>>x.titlu;
        cout<<"URL-u paginii:\n";
        in>>x.url;
        cout<<"Data accesarii:\n";
        in>>x.data;
        return in;
    }
    friend ostream &operator << (ostream &out,fe &x)
    {
        out<<x.nume<<' '<<x.titlu<<' '<<x.url<<' '<<x.data;
        return out;
    }
}forme[100];

void meniu()
{
    cout<<"1. Introduceti un articol\n";
    cout<<"2. Introduceti o carte\n";
    cout<<"3. Introduceti o pagina web\n";
    cout<<"4. Inchiderea meniului\n";
    cout<<"5. Afisare toate referintele\n";
    cout<<"6. afisare2\n";
    cout<<"7. afisare3\n";
    cout<<"8. afisare4\n";
}

void afis1()
{
    int i;
    for (i=1;i<=nra;++i) cout<<art[i]<<'\n';
    for (i=1;i<=nrc;++i) cout<<cart[i]<<'\n';
    for (i=1;i<=nrp;++i) cout<<forme[i]<<'\n';
}

void afis2()
{
    int i;
    int andat;
    cout<<"Introduceti anul dat:\n";
    cin>>andat;
    for (i=1;i<=nra;++i)
        if (art[i].get_an()==andat) cout<<art[i]<<'\n';
    for (i=1;i<=nrc;++i)
        if (cart[i].get_an()==andat) cout<<cart[i]<<'\n';
}

/*void afis3()
{
    int i,j;
    char numedat[100];
    cout<<"Introduceti numele dat:\n";
    cin>>numedat;
    for (i=1;i<=nra;++i)
        for (j=1;j<=art[i].get_nr();++j)
        if (strcpy(art[i].autor[j].nume,numedat)==0) cout<<art[i]<<'\n';
    for (i=1;i<=nrc;++i)
        for (j=1;j<=cart[i].get_nr();++j)
        if (strcpy(cart[i].autor[j].nume,numedat)==0) cout<<cart[i]<<'\n';
} */

int main()
{
    while (rep==0) {
            meniu();
            cout<<"Alegeti optiunea dorita:\n";
            cin>>x;
            if (x==1) {
                    ++nra;
                    cin>>art[nra];
            }
            if (x==2) {
                    ++nrc;
                    cin>>cart[nrc];
            }
            if (x==3) {
                    ++nrp;
                    cin>>forme[nrp];
            }
            if (x==4) {
                    rep=1;
                    return 0;
            }
            if (x==5)
                    afis1();
            if (x==6)
                    afis2();
    }

    return 0;
}
