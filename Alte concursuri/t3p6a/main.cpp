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

void add2(nod *&prim,int x)
{
    nod *q=new nod;
    q->inf=x;
    q->urm=prim;
    prim=q;
}

int n,i,x;

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


    nod *prim1=new nod;
    prim1->urm=NULL;
    while (prim!=NULL) {
        add2(prim1,prim->inf);
        prim=prim->urm;
    }

    while (prim1->urm!=NULL) {
        cout<<prim1->inf<<' ';
        prim1=prim1->urm;
    }

    return 0;
}
