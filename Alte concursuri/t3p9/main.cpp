#include <iostream>

using namespace std;

struct nod {
    int inf;
    int ind;
    nod *urm;
};

void add(nod *&prim,int x,int i)
{
    nod *q=new nod;
    q->inf=x;
    q->ind=i;
    q->urm=NULL;
    if (prim==NULL) prim=q;
    else
    {
        nod *p=prim;
        while (p->urm!=NULL)
            p=p->urm;
        p->urm=q;
    }
}

int n,m,i,x,p,nr;

int main()
{
    cin>>n>>m;
    nod *prim1=new nod;
    nr=1;
    cin>>prim1->inf;
    while (prim1->inf==0) {
    cin>>prim1->inf;
    nr++;
    }
    prim1->ind=nr;
    prim1->urm=NULL;

    for (i=nr+1;i<=n;i++) {
        cin>>x;
        if (x!=0)
        add(prim1,x,i);
    }

    nod *prim2=new nod;
    cin>>prim2->inf;
    nr=1;
    while (prim2->inf==0) {
        cin>>prim2->inf;
        nr++;
    }
    prim2->ind=nr;
    prim2->urm=NULL;

    for (i=nr+1;i<=m;i++) {
        cin>>x;
        if (x!=0)
        add(prim2,x,i);
    }

    p=0;
    while (prim1!=NULL &&prim2!=NULL) {
        if (prim1->ind<prim2->ind) {
            cout<<prim1->inf<<"pe indicele "<<prim1->ind<<'\n';
            prim1=prim1->urm;
        }
        else
        if (prim1->ind>prim2->ind) {
            cout<<prim2->inf<<"pe indicele "<<prim2->ind<<'\n';
            prim2=prim2->urm;
        }
        else
        if (prim1->ind==prim2->ind) {
            cout<<prim1->inf+prim2->inf<<"pe indicele "<<prim1->ind<<'\n';
            p=p+prim1->inf*prim2->inf;
            prim1=prim1->urm;
            prim2=prim2->urm;
        }
    }

    while (prim1!=NULL) {
          cout<<prim1->inf<<"pe indicele "<<prim1->ind<<'\n';
          prim1=prim1->urm;
    }

    while (prim2!=NULL) {
         cout<<prim2->inf<<"pe indicele "<<prim2->ind<<'\n';
         prim2=prim2->urm;
    }

    cout<<"Produsul scalar este "<<p;

    return 0;
}
