#include <iostream>

using namespace std;

struct nod {
    int coef;
    int grad;
    nod *urm;
};

void add(nod *&prim,int x,int i)
{
    nod *q=new nod;
    q->coef=x;
    q->grad=i-1;
    q->urm=prim;
    prim=q;
}

int n,m,i,x;

int main()
{
    cin>>n>>m;

    nod *prim1=new nod;
    cin>>prim1->coef;
    prim1->grad=0;
    prim1->urm=NULL;

    for (i=2;i<=n;i++) {
        cin>>x;
        add(prim1,x,i);
    }

    nod *prim2=new nod;
    cin>>prim2->coef;
    prim2->grad=0;
    prim2->urm=NULL;

    for (i=2;i<=m;i++) {
        cin>>x;
        add(prim2,x,i);
    }



    nod *prim3=new nod;
    prim3->urm=NULL;
    while (prim1!=NULL &&prim2!=NULL) {
        if (prim1->grad>prim2->grad) {
            add(prim3,prim1->coef,prim1->grad+1);
            prim1=prim1->urm;
        }
        else
        if (prim1->grad<prim2->grad) {
            add(prim3,prim2->coef,prim2->grad+1);
            prim2=prim2->urm;
        }
        else
        if (prim1->grad==prim2->grad) {
           add(prim3,prim1->coef+prim2->coef,prim1->grad+1);
            prim2=prim2->urm;
            prim1=prim1->urm;
        }
    }

    while (prim1!=NULL) {
        add(prim3,prim1->coef,prim1->grad+1);
        prim1=prim1->urm;
    }

    while (prim2!=NULL) {
        add(prim3,prim2->coef,prim2->grad+1);
        prim2=prim2->urm;
    }



     while (prim3->urm!=NULL) {
        if (prim3->coef!=0) {
        if (prim3->coef>0) cout<<"+";
        cout<<prim3->coef<<"X^"<<prim3->grad<<' ';
        }
        prim3=prim3->urm;
    }

    return 0;
}
