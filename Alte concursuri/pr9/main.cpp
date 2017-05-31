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
    q->urm=prim;
    prim=q;
}

int n,m,i,x,t;

int main()
{
    cin>>n>>m;

    nod *prim1=new nod;
    cin>>prim1->inf;
    prim1->urm=NULL;

    for (i=2;i<=n;i++) {
        cin>>x;
        add(prim1,x);
    }

    nod *prim2=new nod;
    cin>>prim2->inf;
    prim2->urm=NULL;

    for (i=2;i<=m;i++) {
        cin>>x;
        add(prim2,x);
    }

    nod *prim3=new nod;
    prim3->urm=NULL;

    while (prim1!=NULL &&prim2!=NULL) {
        if (prim1->inf+prim2->inf+t>9) {
            add(prim3,(prim1->inf+prim2->inf+t)%10);
            t=1;
        }
        else {
            add(prim3,(prim1->inf+prim2->inf)+t);
            t=0;
        }
        prim1=prim1->urm;
        prim2=prim2->urm;
    }

    while (prim1!=NULL) {
        add(prim3,prim1->inf+t);
        if (t==1) t=0;
        prim1=prim1->urm;
    }

    while (prim2!=NULL) {
        add(prim3,prim2->inf+t);
        if (t==1) t=0;
        prim2=prim2->urm;
    }

    while (prim3->urm!=NULL) {
        cout<<prim3->inf;
        prim3=prim3->urm;
    }

    return 0;
}
