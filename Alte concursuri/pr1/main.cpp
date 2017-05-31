#include <iostream>

using namespace std;

struct nod{
    int info;
    nod *urm;
    };

int n,i,x,ok;

void add(nod *&prim,int x)
{
    nod *q=new nod;
    q->info=x;
    q->urm=prim;
    prim=q;
}

void afis(nod *prim)
{
    nod *p=prim;
    while (p!=NULL) {
        cout<<p->info<<' ';
        p=p->urm;
    }
    cout<<'\n';
}

int cautare (nod *prim,int x)
{
    int ok=0;
    nod *p=prim;
    while (p!=NULL &&ok==0) {
        if (p->info==x) ok=1;
        p=p->urm;
    }
    return ok;
}


int main()
{
    cin>>n;

    nod *prim=new nod;
    cin>>prim->info;
    prim->urm=NULL;

    for (i=2;i<=n;i++) {
        cin>>x;
        add(prim,x);
    }

    afis(prim);

    cin>>x;

    ok=cautare (prim,x);
    if (ok==1) cout<<"DA";
    else
    cout<<"NU";

    return 0;
}
