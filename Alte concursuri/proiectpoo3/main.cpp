#include <iostream>

using namespace std;

template <class T>
class lista;
template <class T>
class deque_m;

template <class T>
class nod{
         T info;
         nod <T> *leg;
        public:
        //int get_info() {return info;};
       //nod *get_leg() {return leg;};
        friend class lista <T>;
        friend class deque_m <T>;
};

template <class T>
class lista{
    int nr;
    protected: nod <T> *prim;
    public:
       nod  <T> *get_prim() {return prim;}
       int get_nr() {return nr;}
       void set_nr() {nr++;}
       void set1_nr() {--nr;}
       void setl(nod <T> *x) {prim=x;}
       lista()
       {
           prim=NULL;
       }
       ~lista() {}
         void inserarelainceput(nod <T> *prim); //virtual
         void inserarelasfarsit(nod <T> *prim); //virtual
         void inserareinterior(nod <T> *prim,int poz,T val);
         void stergere (nod <T> *prim,int poz); //virtual
         void inversare ();
         void afiseaza(nod <T> *prim);
         void citeste(nod <T> *prim);
         void delk(nod <T> *prim,int k);
};

template <class T>
class deque_m: public lista <T>
{
    public:
        deque_m() {
           lista <T> ::prim=NULL;
        }
        ~deque_m() {
           lista <T> :: ~lista();
        }
    //void inserarelainceput(nod <T> *prim,T val);
   // void inserarelasfarsit(nod <T> *prim,T val);
   // void stergere(nod <T> *prim,int poz);
};

deque_m <int> d;

void meniu()
{
    cout<<"----------MENIU----------\n";
    cout<<"1.Citirea listei(deque)\n";
    cout<<"2.Adaugarea unui element la inceput\n";
    cout<<"3.Adaugarea unui element la sfarsit\n";
    cout<<"4.Stergerea unui element la inceput\n";
    cout<<"5.Stergerea unui element la sfarsit\n";
    cout<<"6.Inversarea listei\n";
    cout<<"7.Stergerea din k in k a listei\n";
    cout<<"8.Afisarea listei\n";
    cout<<"9.Iesirea din program\n";
}

template <class T>
void lista <T> :: inserarelainceput(nod <T> *prim)
{
    T val;
    cin>>val;
    nod <T> *elem=new nod <T>;
    elem->info=val;
    elem->leg=prim;
    prim=elem;
    d.set_nr();
    setl(prim);
}

template <class T>
void lista <T> :: inserarelasfarsit(nod <T> *prim)
{
    T val;
    cin>>val;
    nod <T> *p=prim;
    nod <T> *q=new nod <T>;
    q->info=val;
    q->leg=NULL;
    if (prim==NULL) prim=q;
    else {
        nod <T> *p=prim;
        while (p->leg!=NULL)
            p=p->leg;
        p->leg=q;
    }
    d.set_nr();
    setl(p);
}

template <class T>
void lista <T> :: stergere(nod <T> *prim,int poz) {
    if (prim==NULL) {
        cout<<"Nu avem elemente in lista\n";return;}
    if (poz==1) {
        nod <T>* x=prim;
        prim=prim->leg;
        delete x;
        d.set1_nr();
        setl(prim);
        return;
    }

    nod <T> *p=prim;
    int i=1;
    while (prim!=NULL &&i+1<poz) {
        prim=prim->leg;
        i++;
    }

    nod <T> *x=prim->leg;
    prim->leg=prim->leg->leg;
    delete x;

    d.set1_nr();
    setl(p);
}

template <class T>
void lista <T> :: afiseaza(nod <T> *prim)
{
    nod  <T>*q;
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

template <class T>
void lista <T> ::inversare()
{
    if (prim==NULL) return;
    nod <T> *prev=NULL, *curent=NULL, *next=NULL;
    curent=prim;
    while (curent!=NULL) {
            next=curent->leg;
            curent->leg=prev;
            prev=curent;
            curent=next;
    }
    prim=prev;
}

template <class T>
void lista <T> :: delk (nod <T> *prim,int k)
{
    int i;nod <T> *t;
    nod <T> *p=prim;
    while (prim->leg!=NULL) prim=prim->leg;
    prim->leg=p;
    prim=p;
    cout<<"Elementele sterse sunt: ";
    while (d.nr>1) {
        for (i=0;i+2<k;i++) prim=prim->leg;
            t=prim->leg;
            prim->leg=prim->leg->leg;
            prim=prim->leg;
            cout<<t->info<<" ";
            delete t;
            d.set1_nr();
    }
    prim->leg=NULL;
    setl(prim);
}

template <class T>
void lista <T> :: citeste(nod <T> *prim)
{
        int i;
        T x;
        d.prim=NULL;
        nod <T> *u;
        u=d.prim;
        cout<<"Introduceti numarul de elemente al listei:\n";
        cin>>d.nr;
        cout<<"Introduceti elementele listei\n";
            for (i=1;i<=d.nr;++i) {
                cin>>x;
            if (d.prim==NULL) {
                d.prim=new nod <T>;
                d.prim->info=x;
                d.prim->leg=NULL;
                u=d.prim;
            }
            else {
            nod <T> *t=new nod <T>;
            t->info=x;
            t->leg=NULL;
            u->leg=t;
            u=t;
            }
        }
}

int main()
{
    int rep=0,x,k;
    meniu();
    while (rep==0) {
         cout<<"\nAlegeti optiunea dorita:\n";
         cin>>x;
        if (x==1)
            d.citeste(d.get_prim());
        if (x==2) {
            cout<<"Valoarea noului element este\n";
            d.inserarelainceput (d.get_prim());
        }
        if (x==3) {
            cout<<"Valoarea noului element este\n";
            d.inserarelasfarsit(d.get_prim());
        }
        if (x==4)
            d.stergere(d.get_prim(),1);
        if (x==5)
            d.stergere(d.get_prim(),d.get_nr());
        if (x==6) {
                if (!d.get_prim()) cout<<"Lista este vida,nu o putem inversa\n";
                else {
                d.inversare();
                d.afiseaza(d.get_prim());
                }
        }
        if (x==7) {
                if (!d.get_prim()) cout<<"Lista este vida,nu putem sterge din k in k\n";
                    else {
                    cout<<"Introduceti elementul k:";
                    cin>>k;
                    d.delk(d.get_prim(),k);
                }
        }
        if (x==8)
            d.afiseaza(d.get_prim());
        if (x==9) {
                rep=1;
                return 0;
        }
        if (x>9)
            cout<<"Optiunea aleasa nu exista\n";
        }

    return 0;
}
