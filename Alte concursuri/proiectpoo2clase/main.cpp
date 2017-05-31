#include <iostream>
#include <fstream>

using namespace std;

class lista;

class nod{
         int info;
         nod *leg;
        public:
        int get_info() {return info;};
         nod *get_leg() {return leg;};
        friend class lista;
        friend istream & operator >>(istream & in,lista &l);
        friend ifstream & operator >> (ifstream & fin,lista &l);
};

class lista{
    int nr;
    nod *prim;
    public:
       nod *get_prim() {return prim;}
       int get_nr() {return nr;}
       void set_nr() {nr++;}
       void set1_nr() {--nr;}
       void setl(nod *x) {prim=x;}
       void setlung(int x) {nr=x;}
       lista()
       {
           prim=NULL;
       }
         void inserarelainceput(nod *prim,int val);
         void inserarelasfarsit(nod *prim,int val);
         void inserareinterior(nod *prim,int poz,int val);
         void stergere (nod *prim,int poz);
         nod* inversare(nod *prim);
         void afiseaza(nod *prim);
         void delk(nod *prim,int k);
        friend ostream & operator <<(ostream & out,lista l );
        friend istream & operator >>(istream & in,lista &l);
        friend ifstream & operator >> (ifstream & fin,lista &l);
        lista operator + (lista l1);
}l;

void lista :: inserarelainceput(nod *prim,int val)
{
    nod *elem=new nod;
    elem->info=val;
    elem->leg=prim;
    prim=elem;
    l.set_nr();
    setl(prim);
}

void lista :: inserarelasfarsit(nod *prim,int val)
{
    nod *p=prim;
    nod *q=new nod;
    q->info=val;
    q->leg=NULL;
    if (prim==NULL) prim=q;
    else {
        nod *p=prim;
        while (p->leg!=NULL)
            p=p->leg;
        p->leg=q;
    }
    l.set_nr();
    setl(p);
}

void lista :: inserareinterior(nod *prim,int poz,int x)
{
    nod *elem=new nod;
    elem->info=x;
    elem->leg=NULL;

    if (prim==NULL) {
        prim=elem;
        return;
    }

    nod *p=new nod;
    p=prim;
    for (int i=1;i<poz-1;++i)
        p=p->leg;

    if (prim==p) {
        elem->leg=prim->leg;
        prim->leg=elem;
        l.set_nr();
        setl(prim);
        return;
    }

    elem->leg=p->leg;
    p->leg=elem;

    l.set_nr();
    setl(prim);
}

void lista :: stergere(nod *prim,int poz) {
    if (prim==NULL) {
        cout<<"Nu avem elemente in lista\n";return;}
    if (poz==1) {
        nod* x=prim;
        prim=prim->leg;
        delete x;
        l.set1_nr();
        setl(prim);
        return;
    }

    nod *p=prim;
    int i=1;
    while (prim!=NULL &&i+1<poz) {
        prim=prim->leg;
        i++;
    }

    nod *x=prim->leg;
    prim->leg=prim->leg->leg;
    delete x;

    l.set1_nr();
    setl(p);
}

nod* lista ::  inversare(nod *prim)
{
    nod *q,*t;
    if (prim->leg==NULL) return prim;
    q=prim->leg;
    t=inversare(prim->leg);
    q->leg=prim;
    prim->leg=NULL;
    setl(t);
    return t;
}

void lista :: delk (nod *prim,int k)
{
    int i;nod *t;
    nod *p=prim;
    while (prim->leg!=NULL) prim=prim->leg;
    prim->leg=p;
    prim=p;
    cout<<"Elementele sterse sunt: ";
    while (l.nr>1) {
        for (i=0;i+2<k;i++) prim=prim->leg;
            t=prim->leg;
            prim->leg=prim->leg->leg;
            prim=prim->leg;
            cout<<t->info<<" ";
            delete t;
            l.set1_nr();
    }
    prim->leg=NULL;
    setl(prim);
}

istream & operator >> (istream & in,lista &l)
{
    int i,x;
    l.prim=NULL;
    nod *u;
    u=l.prim;
    in>>l.nr;
    for (i=1;i<=l.nr;++i) {
        in>>x;
        if (l.prim==NULL) {
            l.prim=new nod;
            l.prim->info=x;
            l.prim->leg=NULL;
            u=l.prim;
        }
        else {
        nod *t=new nod;
        t->info=x;
        t->leg=NULL;
        u->leg=t;
        u=t;
        }
    }

    return in;
}

ifstream f("intrare.in");

ifstream & operator >> (ifstream & fin,lista &l)
{
    int i,x;
    l.prim=NULL;
    nod *u;
    u=l.prim;
    fin>>l.nr;
    for (i=1;i<=l.nr;++i) {
        fin>>x;
        if (l.prim==NULL) {
            l.prim=new nod;
            l.prim->info=x;
            l.prim->leg=NULL;
            u=l.prim;
        }
        else {
        nod *t=new nod;
        t->info=x;
        t->leg=NULL;
        u->leg=t;
        u=t;
        }
    }

    return fin;
}

ostream & operator <<(ostream & out,lista l )
{
    nod *q;
    int nr=0;
    if (l.prim) {
        out<<"\nElementele listei sunt: ";
        for(q=l.get_prim();q;q=q->get_leg()) {
            out<<q->get_info()<<" ";
            ++nr;
            if (nr==l.get_nr()) break;
        }
        out<<'\n';
        }
     else
    out<<"\nLista este vida!\n";
    return out;
}

void lista :: afiseaza(nod *prim)
{
    nod *q;
    if(prim)
    {
    cout<<"\nElementele listei sunt: ";
    for(q=prim;q;q=q->leg)
        cout<<q->info<<" ";
    cout<<'\n';
    }
     else
    cout<<"\nLista este vida!\n";
}

lista lista :: operator + (lista l1)
{
    lista temp;
    temp.prim=prim;
    while (prim->leg!=NULL)
            prim=prim->leg;
    prim->leg=l1.prim;
    return temp;
}

void meniu()
{
    cout<<"-------MENIU-------\n";
    cout<<"1.Adaugarea unui nou element pe o pozitie data\n";
    cout<<"2.Stergerea unui element de pe o pozitie data\n";
    cout<<"3.Inversarea listei\n";
    cout<<"4.Stergerea din k in k a listei\n";
    cout<<"5.Concaternarea a doua liste\n";
    cout<<"6.Afisarea listei\n";
    cout<<"7.Iesirea din program\n";
}


int main()
{
    int x,val,poz,rep=0,k;
    meniu();

    cout<<"\nIntroduceti numarul de elemente si elementele listei: ";
    cin>>l;
    lista l1;
    f>>l1;

    while (rep==0) {
    cout<<"\nAlegeti optiunea dorita:\n";
    cin>>x;
    if (x==1) {
         cout<<"Valoarea noului element este: ";
         cin>>val;
         cout<<"Pozitia pe care va fi introdus noul element este: ";
         cin>>poz;
         if (poz<=0) cout<<"Pozitia nu exista\n";
         else
         if (poz==1) l.inserarelainceput(l.get_prim(),val);
         else
         if (poz==l.get_nr()+1) l.inserarelasfarsit(l.get_prim(),val);
         else
         if (poz>l.get_nr()) cout<<"Pozitia nu exista\n";
         else
         l.inserareinterior(l.get_prim(),poz,val);
    }

    if (x==2) {
        cout<<"Introduceti pozitia de pe care va fi sters elementul:";
        cin>>poz;
        if (poz<=0) cout<<"Nu exista aceasta pozitie in lista\n";
        else
        if (poz>l.get_nr()) cout<<"Lista nu are atatea elemente\n";
        else
        l.stergere(l.get_prim(),poz);
    }

    if (x==3) {
        if (!l.get_prim()) cout<<"Lista este vida,nu o putem inversa\n";
        else {
        nod *t=l.inversare(l.get_prim());
        l.afiseaza(t);
        }
    }

    if (x==4) {
        if (!l.get_prim()) cout<<"Lista este vida,nu putem sterge din k in k\n";
        else {
        cout<<"Introduceti elementul k:";
        cin>>k;
        l.delk(l.get_prim(),k);
        }
    }

    if (x==5) {
           int elem=l.get_nr()+l1.get_nr();
            if (l.get_nr()==0) l=l1;
            else
            l=l+l1;
            l.setlung(elem);
            cout<<l;
    }

    if (x==6) cout<<l;
    if (x==7) {rep=1;return 0;}
    if (x>7) cout<<"Aceasta optiune nu exista\n";
    }

    return 0;
}
