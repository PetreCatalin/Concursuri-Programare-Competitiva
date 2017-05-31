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

int n,x,i,elem;

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

    add(prim,32000);

    nod *elem=new nod;
    cin>>elem->inf;

    if (elem->inf <=prim->inf) {
        elem->urm=prim;
        prim=elem;
    }
    else
    {
        nod *c,*c1;
        c=prim;
        c1=prim->urm;
        while (c1->inf<elem->inf) {
            c=c->urm;
            c1=c1->urm;
        }
        c->urm=elem;
        elem->urm=c1;
    }

    while (prim->urm!=NULL) {
        cout<<prim->inf<<' ';
        prim=prim->urm;
    }

    return 0;
}
