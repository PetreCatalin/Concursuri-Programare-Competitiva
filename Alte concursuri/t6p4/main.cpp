#include <iostream>

using namespace std;

struct arbore {
    int inf;
    arbore *st,*dr;
};

arbore *p;
int n,i,x,k1,k2;

void insert(arbore *&p,int k)
{
    if (p==NULL)
    {
        p=new arbore;
        p->inf=k;
        p->st=p->dr=NULL;
    }
    else {
        if (k<p->inf) insert(p->st,k);
        else
        insert(p->dr,k);
    }
}

void preordine(arbore *p)
{
    if (p==NULL) return;
    if (p->inf>=k1 &&p->inf<=k2) cout<<p->inf<<' ';
    preordine(p->st);
    preordine(p->dr);
}

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        insert(p,x);
    }

    cin>>k1>>k2;

    preordine(p);

    return 0;
}
