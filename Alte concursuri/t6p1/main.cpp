#include <iostream>

using namespace std;

struct arbore {
    int inf;
    arbore *st,*dr;
};

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
    cout<<p->inf<<' ';
    preordine(p->st);
    preordine(p->dr);
}

void inordine (arbore *p)
{
    if (p==NULL) return;
    inordine(p->st);
    cout<<p->inf<<' ';
    inordine(p->dr);
}

void postordine (arbore *p)
{
    if (p==NULL) return;
    postordine(p->st);
    postordine(p->dr);
    cout<<p->inf<<' ';
}

int n,i,x;
arbore *p;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        insert(p,x);
    }

    preordine(p);
    cout<<'\n';
    inordine(p);
    cout<<'\n';
    postordine(p);

    return 0;
}
