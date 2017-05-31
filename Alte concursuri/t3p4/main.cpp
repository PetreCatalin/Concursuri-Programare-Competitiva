#include <iostream>

using namespace std;

struct nod {
    int inf;
    nod *urm;
};

void add(nod *&prim,int x)
{
    nod *q=new nod;
    q->inf=x;
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

void stergere (nod *&prim,int k)
{
    int nr=1;
    nod *c1,*p;
    p=prim;
    while (nr<k) {
        nr++;
        c1=p;
        p=p->urm;
    }
    if (c1==NULL) {
        c1=prim;
        prim=prim->urm;
        delete c1;
    }
    else {
        c1->urm=p->urm;
        delete p;
    }
}

int n,i,x,k;

int main()
{
    cin>>n;
    nod *prim=new nod;
    cin>>prim->inf;
    prim->urm=NULL;

    for (i=2;i<=n;i++) {
        cin>>x;
        add(prim,x);
    }

    cin>>k;
    stergere (prim,k);

    while (prim!=NULL) {
        cout<<prim->inf<<' ';
        prim=prim->urm;
    }


    return 0;
}
