#include <iostream>
#include <cmath>

using namespace std;

struct nod {
    int info;
    int grad;
    nod *urm;
    };

void add(nod *&prim,int x,int i)
{
    nod *q=new nod;
    q->info=x;
    q->grad=i-1;
    q->urm=prim;
    prim=q;
}

int calcul(nod *prim,int x)
{
    int val=0;
    nod *p=prim;
    while (p!=NULL) {
        val=val+(p->info)*pow(x,p->grad);
        p=p->urm;
    }
    return val;
}

int n,i,x,rez;

int main()
{
    cin>>n;

    nod *prim=new nod;
    cin>>prim->info;
    prim->grad=0;
    prim->urm=NULL;

    for (i=2;i<=n;i++) {
        cin>>x;
        add(prim,x,i);
    }

    cin>>x;

    rez=calcul(prim,x);
    cout<<rez;

    return 0;
}
