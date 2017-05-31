#include <iostream>
using namespace std;
int x,n,k;

struct nod {
    double info;
    nod *urm,*prec;
            }*p;

void inceput(double x,nod *&p)
{
    nod *q;
    if(p!=0)
    {q=new nod;
    q->info=x;
    q->urm=p;
    q->prec=0;
    p->prec=q;
    p=q;
    }
    else
    {
        p=new nod;
        p->info=x;
        p->urm=0;
        p->prec=0;
    }

}

void sfarsit(double x,nod *&p)
{
    nod *q,*r;
    if(p!=0)
    {q=p;
    while(q->urm!=0)
        q=q->urm;

    r=new nod;
    r->info=x;
    q->urm=r;
    r->urm=0;
    r->prec=q;
    }
    else
       {
        p=new nod;
        p->info=x;
        p->urm=0;
        p->prec=0;
        }
}

void interior(double x,int k,nod *&p)
{
    nod *q,*r;
    if(k==1)
        if(p)
    {q=new nod;
    q->info=x;
    q->urm=p;
    q->prec=0;
    p->prec=q;
    p=q;}
    else
    {
        p=new nod;
        p->info=x;
        p->urm=0;
        p->prec=0;
    }
    else
    {
        int nr=1;
        q=p;
        if(q)
        {while(nr<k-1)
            {nr++;
            if(q->urm)
            q=q->urm;
          else
          {
              cout<<"\nPozitia nu exista!\n";
              return;
          }
            }
        r=new nod;
        r->info=x;
        r->urm=q->urm;
        r->prec=q;
        if(q->urm)
            q->urm->prec=r;
        q->urm=r;
    }
    else
        {
              cout<<"\nPozitia nu exista!\n";
              return;
          }

}
}

void afiseaza(nod *p)
{
    nod *q;
    if(p)
    {cout<<"\nElementele listei sunt: ";
    for(q=p;q;q=q->urm)
        cout<<q->info<<" ";
    cout<<'\n';}
     else
        cout<<"\nLista este vida!\n";
}

void afiseaza_invers(nod *p)
{
    nod *q,*r;

    if(p)
    {cout<<"\nElementele listei sunt: ";
    for(q=p;q->urm!=0;q=q->urm);
    cout<<q->info<<" ";
    q=q->prec;
    for(r=q;r;r=r->prec)
        cout<<r->info<<" ";
    cout<<'\n';}
    else
        cout<<"\nLista este vida!\n";
}

void sterge (int x,nod *&p)
{
    int nr=1;
    nod *q,*r,*t;
    if(x==1)
        if(p)
            {
                if(p->urm)
                    {q=p;
                    p=p->urm;
                    p->prec=0;
                    delete q;
                    return;}
                else
                    {delete p;
                    p=NULL;
                    }
            }
        else
            cout<<"\nLista este vida!\n";

            else
    {q=p;
    if(p)
    {while (q->urm!=0)
        {if(nr==x)
            {
                r=q->prec;
                t=q->urm;
                r->urm=t;
                t->prec=r;
                delete q;
                break;
            }
            q=q->urm;
            nr++;
        }
    if(q->urm==0&&nr==x)
        {
                r=q->prec;
                r->urm=0;
                delete q;
            }
        else
            cout<<"\nPozitia de sters nu exista!\n";
    }
    else
        cout<<"\nLista este vida!\n";
    }

}

void sterge_val(double x,nod *&p)
{   nod *q,*r,*t;
if(p)
 {if(x==p->info)
    if(p->urm)
            {
                q=p;
                p=p->urm;
                p->prec=0;
                delete q;
               return;
            }
        else
        {
            delete p;
            p=NULL;
        }
            else
   {
    q=p;
    while (q->urm!=0)
        {if(q->info==x)
            {
                r=q->prec;
                t=q->urm;
                r->urm=t;
                t->prec=r;
                delete q;
                break;
            }
            q=q->urm;
        }
    if(q->urm==0)
        if(q->info==x)
            {
                r=q->prec;
                r->urm=0;
                delete q;
            }
        else
            cout<<"\nValoare de sters nu exista!\n";
   }
 }
  else
            cout<<"\nValoare de sters nu exista!\n";
}

void meniu(int &ok)
{
    cout<<'\n';
    cout<<"1.Adaugarea unui nou element la inceputul listei\n";
    cout<<"2.Adaugarea unui nou element la finalul listei\n";
    cout<<"3.Adaugarea unui nou element pe o pozitie data\n";
    cout<<"4.Afisarea elementelor in ordinea introducerii lor\n";
    cout<<"5.Afisarea elementelor in ordine inversa\n";
    cout<<"6.Stergerea unui element stiind numarul lui de ordine\n";
    cout<<"7.Stergerea unui element stiind valoarea lui\n";
    cout<<"8.Iesire!\n";
    cout<<"Optiunea aleasa: ";
    int x,k;
    cin>>x;
    double val;
    if(x==1)
    {
        cout<<"Valoarea noului element este: ";
        cin>>val;
        inceput(val,p);
    }
    else
        if(x==2)
    {
         cout<<"Valoarea noului element este: ";
         cin>>val;
         sfarsit(val,p);
    }
    else
    if(x==3)
    {
         cout<<"Valoarea noului element este: ";
         cin>>val;
         cout<<"Pozitia pe care va fi introdus noul element este: ";
         cin>>k;
         interior(val,k,p);

    }
    else
    if(x==4)
        afiseaza(p);
        else
            if(x==5)
                afiseaza_invers(p);
        else
            if(x==6)
        {
            cout<<"Pozitia elementului de sters este: ";
            cin>>k;
            sterge(k,p);
        }
        else
            if(x==7)
            {
            cout<<"Valoarea elementului de sters este: ";
            cin>>val;
            sterge_val(val,p);
            }
            else
                if(x==8)
                ok=0;
            else
                cout<<"\nOptiunea aleasa nu exista!\n\n";
}

int main()
{
int ok=1;
while(ok)
    meniu(ok);
return 0;
}
