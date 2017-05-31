#include <iostream>
#include <cstring>

using namespace std;

int nr,i,pr,rep,nr1,nr2,nr3,optiune;

class angajat
{
    protected:
    char nume[100];
    char prenume[100];
    char tipcontract[100];
    char datainc[100];
    double prima;
};

class angajatcuora: public angajat
{
    char datasf[100];
    public:
    char* get_di() {return datasf;}
    friend istream & operator >> (istream & in,angajatcuora &a)
    {
                cout<<"Introduceti nume: ";
                in>>a.nume;
                cout<<"Introduceti prenume: ";
                in>>a.prenume;
                strcpy(a.tipcontract,"plata cu ora");
                cout<<"Introduceti data inceperii contractului :";
                in>>a.datainc;
                cout<<"Introduceti data incheiesii contractului :";
                in>>a.datasf;
                return in;
    }
    void setprima()
    {
        int x=strlen(datasf);
                int anincheierecontract=(datasf[x-4]-'0')*1000+(datasf[x-3]-'0')*100+(datasf[x-2]-'0')*10+(datasf[x-1]-'0');
                if (anincheierecontract<=2014) prima=pr/2;
                else
                prima=pr;
    }
    friend ostream &operator <<(ostream &out,angajatcuora &a)
    {
        out<<a.nume<<' '<<a.prenume<<','<<a.tipcontract<<','<<a.datainc<<'-'<<a.datasf<<','<<"prima: "<<a.prima<<"\n";
        return out;
    }
}o[10];

class tesa: public angajat
{
    char tipactivitate[100];
    int weekend;
    public:
    int get_weekend(){return weekend;}
    friend istream &operator >>(istream & in,tesa &a)
    {
        cout<<"Introduceti nume: ";
        in>>a.nume;
        cout<<"Introduceti prenume: ";
        in>>a.prenume;
        strcpy(a.tipcontract,"contract permanent");
        cout<<"Intoduceti data inceperii contractului: ";
        in>>a.datainc;
        strcpy(a.tipactivitate,"TESA");
        cout<<"Introduceti numarul weekendului ales: ";
        in>>a.weekend;
        return in;
    }
    void setprima()
    {
        prima=pr;
    }
    friend ostream &operator <<(ostream & out,tesa &a)
    {
         out<<a.nume<<' '<<a.prenume<<','<<a.tipcontract<<','<<a.datainc<<','<<a.tipactivitate<<','<<"weekend "<<a.weekend<<','<<"prima "<<a.prima<<"\n";
         return out;
    }
}t[10];

class lucrativ: public angajat
{
    int nrminori;
    char tipactivitate[100];
    public:
    int get_nrm() {return nrminori;}
    friend istream &operator >>(istream &in,lucrativ &a)
    {
        cout<<"Introduceti numele: ";
        in>>a.nume;
        cout<<"Introduceti prenumele: ";
        in>>a.prenume;
        strcpy(a.tipcontract,"contract permanent");
        cout<<"Intoduceti data inceperii contractului: ";
        in>>a.datainc;
        strcpy(a.tipactivitate,"lucrativ");
        cout<<"Introduceti numarul de minori: ";
        in>>a.nrminori;
        return in;
    }
    friend ostream &operator <<(ostream &out,lucrativ &a)
    {
         out<<a.nume<<' '<<a.prenume<<','<<a.tipcontract<<','<<a.datainc<<','<<a.tipactivitate<<','<<"minori "<<a.nrminori<<','<<"prima "<<a.prima<<"\n";
         return out;
    }
    void setprima()
    {
        int vechime,x,nr;
        x=strlen(datainc);
        nr=(datainc[x-4]-'0')*1000+(datainc[x-3]-'0')*100+(datainc[x-2]-'0')*10+(datainc[x-1]-'0');
        vechime=2014-nr;
        double procent= (double) vechime/100;
        prima=pr+nrminori*pr*procent;
    }
}l[10];

void meniu()
{
    cout<<"1.Angajat cu ora\n";
    cout<<"2.Angajat tesa\n";
    cout<<"3.Angajat lucrativ\n";
}

void afis1()
{
    cout<<"\nAfisarea tuturor angajatilor: \n";
    for (i=1;i<=nr1;++i)
        cout<<o[i];
    for (i=1;i<=nr2;++i)
        cout<<t[i];
    for (i=1;i<=nr3;++i)
        cout<<l[i];
}

void afis2()
{
    cout<<"\nAngajati cu copii minori\n ";
    for (i=1;i<=nr3;++i)
        if (l[i].get_nrm()>0) cout<<l[i];
}

void afis3()
{
    cout<<"\nAngajati in al doilea weekend\n ";
    for (i=1;i<=nr2;++i)
        if (t[i].get_weekend()==2) cout<<t[i];
}

void afis4()
{
    cout<<"\nAngajati pana in martie 2015\n";
    int luna,x,an;
    for (i=1;i<=nr1;++i) {
             x=strlen(o[i].get_di());
             an=(o[i].get_di()[x-4]-'0')*1000+(o[i].get_di()[x-3]-'0')*100+(o[i].get_di()[x-2]-'0')*10+(o[i].get_di()[x-1]-'0');
             luna=(o[i].get_di()[x-7]-'0')*10+(o[i].get_di()[x-6]-'0');
            if (an>2015) cout<<o[i];
            else
                if (an==2015 &&luna>=3) cout<<o[i];
    }
}

int main()
{
    cout<<"Introduceti prima: ";
    cin>>pr;
    cout<<"Introduceti numarul de angajati ";
    cin>>nr;
    meniu();
    nr1=0;nr2=0;nr3=0;
    for (i=1;i<=nr;++i) {
            cout<<"\n";
            cout<<"Introduceti optiunea aleasa: ";
            cin>>optiune;
            cout<<"\n";
            if (optiune==1) { //angajat cu ora
                ++nr1;
                cin>>o[nr1];
                o[nr1].setprima();
            }
            if (optiune==2) { //angaj tesa
                ++nr2;
                cin>>t[nr2];
                t[nr2].setprima();
            }
            if (optiune==3) { //angajat  lucrativ
                ++nr3;
                cin>>l[nr3];
                l[nr3].setprima();
            }
    }
            afis1();
            afis2();
            afis3();
            afis4();

    return 0;
}
