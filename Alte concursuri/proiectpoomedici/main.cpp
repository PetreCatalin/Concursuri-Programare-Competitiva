#include <iostream>
#include <cstring>

using namespace std;

int rep,x,nr1,nr2,nr3;

class pacient {
    protected:
    char nume[100],prenume[100],adresa[100],datac[100],datata[100];
    int varsta,colesterol,tensiune,nr;
    public:
        pacient() {
            nr=0;
        }
        int get_nr(){return nr;};
        char *get_nume(){return nume;};
};

class adult:public pacient{};

class pp40: public adult
{
    char fumat[10],sedentarism[10];
public:
    friend istream &operator >> (istream &in,pp40 &a)
    {
        cout<<"nume\n";
        in>>a.nume;
        cout<<"prenume\n";
        in>>a.prenume;
        cout<<"adresa\n";
        in>>a.adresa;
        cout<<"varsta\n";
        in>>a.varsta;
        cout<<"data colesterol\n";
        in>>a.datac;
        cout<<"colesterol\n";
        in>>a.colesterol;
        cout<<"data tensiune arteriala\n";
        in>>a.datata;
        cout<<"tensiune arteriala\n";
        in>>a.tensiune;
        cout<<"Fumator: \n";
        in>>a.fumat;
        cout<<"sedentarism\n";
        in>>a.sedentarism;
        return in;
    }
    friend ostream &operator <<(ostream &out,pp40 &a)
    {
        a.nr=0;
        out<<a.nume<<' '<<a.prenume<<" Risc cardiovascular -";
        if (a.tensiune>139) ++a.nr;
        if (a.colesterol>=240) ++a.nr;
        if (strcmp(a.fumat,"da")==0) ++a.nr;
        if (strcmp(a.sedentarism,"ridicat")==0) ++a.nr;
        if (a.nr==1)  out<<"DA ";
        else
        if (a.nr==0)  out<<"NU ";
        else
        out<<"RIDICAT ";
        out<<"colesterol("<<a.datac<<");"<<a.colesterol<<"mg/dl; TA("<<a.datata<<"):"<<a.tensiune;
        out<<" ;fumator: "<<a.fumat<<" ;sedentarism: "<<a.sedentarism;
        return out;
    }
}pp[100];

class ps40 :public adult
{
     friend istream &operator >> (istream &in,ps40 &a)
    {
        cout<<"nume\n";
        in>>a.nume;
        cout<<"prenume\n";
        in>>a.prenume;
        cout<<"adresa\n";
        in>>a.adresa;
        cout<<"varsta\n";
        in>>a.varsta;
        cout<<"data colesterol\n";
        in>>a.datac;
        cout<<"colesterol\n";
        in>>a.colesterol;
        cout<<"data tensiune arteriala\n";
        in>>a.datata;
        cout<<"tensiune arteriala\n";
        in>>a.tensiune;
        return in;
    }
     friend ostream &operator <<(ostream &out,ps40 &a)
    {
        a.nr=0;
        out<<a.nume<<' '<<a.prenume<<" Risc cardiovascular -";
        if (a.tensiune>139) ++a.nr;
        if (a.colesterol>=240) ++a.nr;
        if (a.nr==0) out<<"NU ";
        if (a.nr==1) out<<"DA ";
        if (a.nr==2) out<<"RIDICAT ";
        out<<"colesterol("<<a.datac<<");"<<a.colesterol<<"mg/dl; TA("<<a.datata<<"):"<<a.tensiune;
        return out;
    }
}ps[100];

class copil: public pacient
{
    char datapc[100],antecedente[100],numem[100],numet[100];
    double prc;
     friend istream &operator >> (istream &in,copil &a)
    {
        cout<<"nume\n";
        in>>a.nume;
        cout<<"prenume\n";
        in>>a.prenume;
        cout<<"adresa\n";
        in>>a.adresa;
        cout<<"varsta\n";
        in>>a.varsta;
        cout<<"data colesterol\n";
        in>>a.datac;
        cout<<"colesterol\n";
        in>>a.colesterol;
        cout<<"data tensiune arteriala\n";
        in>>a.datata;
        cout<<"tensiune arteriala\n";
        in>>a.tensiune;
        cout<<"dataproteinac\n";
        in>>a.datapc;
        cout<<"proteina c\n";
        in>>a.prc;
        cout<<"antecedente\n";
        in>>a.antecedente;
        cout<<"numemama\n";
        in>>a.numem;
        cout<<"numetata\n";
        in>>a.numet;
        return in;
    }
    friend ostream &operator <<(ostream &out,copil &a)
    {
        a.nr=0;
        out<<a.nume<<' '<<a.prenume<<" Risc cardiovascular -";
        if (a.tensiune>139) ++a.nr;
        if (a.colesterol>=240) ++a.nr;
        if (a.prc>0.60) ++a.nr;
        if (a.nr==0) out<<"NU ";
        if (a.nr==1) out<<"DA ";
        if (a.nr>=2) out<<"RIDICAT ";
        out<<"colesterol("<<a.datac<<");"<<a.colesterol<<"mg/dl; TA("<<a.datata<<"):"<<a.tensiune;
        out<<"proteina c reactiva ( "<<a.datapc<<"): "<<a.prc<<" mg/dl ,"<<" Antecedente familie "<<a.antecedente;
        out<<"; mama "<<a.numem<<"; tata "<<a.numet;
        return out;
    }
}c[100];

void  meniu()
 {
     cout<<"1.introducere pacient peste 40\n";
     cout<<"2.introducere pacient sub 40\n";
     cout<<"3.introducere copil\n";
     cout<<"4.inchidere meniu\n";
     cout<<"5.afis1\n";
     cout<<"6.afis2\n";
     cout<<"7.afis3\n";
     cout<<"8.afis4\n";
 }

 void afis1()
 {
    cout<<"adulti\n";
    int i;
    cout<<"adulti peste 40\n";
    for (i=1;i<=nr1;++i)
        cout<<pp[i]<<"\n";
    cout<<"adulti sub 40\n";
    for (i=1;i<=nr2;++i)
        cout<<ps[i]<<"\n";
    cout<<"copii\n";
    for (i=1;i<=nr3;++i)
        cout<<c[i]<<"\n";
    cout<<"\n";
 }

 void afis2()
 {
    int i;
    cout<<"adulti peste 40\n";
    for (i=1;i<=nr1;++i)
       if (pp[i].get_nr()>=2) cout<<pp[i]<<"\n";
    cout<<"adulti sub 40\n";
    for (i=1;i<=nr2;++i)
       if (ps[i].get_nr()==2) cout<<ps[i]<<"\n";

    cout<<"\n";
 }

 void afis3()
 {
     int i;
     for (i=1;i<=nr3;++i)
        if (c[i].get_nr()>0) cout<<c[i]<<"\n";
 }

 void afis4()
 {
     int i;
     char n[100];
     cout<<"introduceti nume dat\n";
     cin>>n;
     cout<<"adulti\n";
     cout<<"adulti peste 40\n";
    for (i=1;i<=nr1;++i)
        if (strcmp(pp[i].get_nume(),n)==0)
        cout<<pp[i]<<"\n";
    cout<<"adulti sub 40\n";
    for (i=1;i<=nr2;++i)
         if (strcmp(ps[i].get_nume(),n)==0)
        cout<<ps[i]<<"\n";
    cout<<"copii\n";
    for (i=1;i<=nr3;++i)
         if (strcmp(c[i].get_nume(),n)==0)
        cout<<c[i]<<"\n";
 }


int main()
{
    rep=0;
    while (rep==0) {
        meniu();
        cout<<"Introduceti optiunea dorita\n";
        cin>>x;
        if (x==1) {
                ++nr1;
                cin>>pp[nr1];
        }
        if (x==2) {
                ++nr2;
                cin>>ps[nr2];
        }
        if (x==3) {
                ++nr3;
                cin>>c[nr3];
        }
        if (x==4) {
                rep=1;
                return 0;
        }
        if (x==5) afis1();
        if (x==6) afis2();
        if (x==7) afis3();
        if (x==8) afis4();
    }

    return 0;
}
