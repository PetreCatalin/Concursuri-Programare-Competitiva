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

void sterge(nod *&prim,nod *p)
{
    nod *temp=p->urm;
    p->urm=p->urm->urm;
    delete temp;
}

int n,x,k,i,nr;

int main()
{
    cin>>n>>k;
    nod *prim=new nod;
    prim->inf=1;
    prim->urm=NULL;

    for (i=2;i<=n;i++)
        add(prim,i);

    nod *p=prim;
    while (p->urm!=NULL) p=p->urm;
    p->urm=prim;
    prim=p->urm;

    nr=n;
    while (nr>1) {
        for (i=1;i<=k-1;i++)
            p=p->urm;
        sterge (prim,p);
        nr=nr-1;
    }

    cout<<p->inf;

    return 0;
}
