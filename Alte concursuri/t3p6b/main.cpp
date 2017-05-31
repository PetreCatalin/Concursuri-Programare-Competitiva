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

nod *inv(nod *p)
{
    nod *q,*t;
    if (p->urm==NULL)
        return p;
    q=p->urm;
    t=inv(p->urm);
    q->urm=p;
    p->urm=NULL;
    return t;
}

int n,x,i;

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

    prim=inv(prim);
    while (prim!=NULL) {
        cout<<prim->inf<<' ';
        prim=prim->urm;
    }

    return 0;
}
