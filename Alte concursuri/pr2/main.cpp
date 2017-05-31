#include <iostream>

using namespace std;

struct nod {
    int inf;
    nod *urm;
};

void add1(nod *&prim,int x)
{
    nod *q=new nod;
    q->inf=x;
    q->urm=prim;
    prim=q;
}

void add2(nod *&prim,int x)
{
    nod *q=new nod;
    q->inf=x;
    q->urm=NULL;
    if (prim==NULL) prim=q;
    else {
        nod *p=prim;
        while (p->urm!=NULL)
            p=p->urm;
        p->urm=q;
    }
}

void add3(nod *&prim,nod *p,int x)
{
    nod *q=new nod;
    q->inf=x;
    q->urm=NULL;

    if (prim==NULL) prim=q;
    else
    if (prim==p) {
        q->urm=prim;
        prim=q;
    }

    q->urm=p->urm;
    p->urm=q;
}

void afis(nod *prim)
{
    while (prim!=NULL) {
        cout<<prim->inf<<' ';
        prim=prim->urm;
    }
}


int n,i,x;

int main()
{
    cin>>n;
    nod *prim1=new nod;
    cin>>prim1->inf;
    prim1->urm=NULL;
    for (i=2;i<=n;i++) {
        cin>>x;
        add1(prim1,x);
    }

    afis(prim1);
    cout<<'\n';

    cin>>n;
    nod *prim2=new nod;
    cin>>prim2->inf;
    prim2->urm=NULL;
    for (i=2;i<=n;i++) {
        cin>>x;
        add2(prim2,x);
    }

    afis(prim2);
    cout<<'\n';

    cin>>x;
    add3(prim1,prim1->urm->urm,x);
    afis(prim1);

    return 0;
}
