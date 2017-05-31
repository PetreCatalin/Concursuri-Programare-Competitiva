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

void search (arbore *p,int x,int &ok)
{
    if (p==NULL) return;
    if (p->inf==x) ok=1;
    search(p->st,x,ok);
    search(p->dr,x,ok);
}

int findmax(arbore *p)
{
    while (p->dr!=NULL)
        p=p->dr;
    return p->inf;
}

void maxst(arbore *&p,arbore *&t)
{
    arbore *x;
    if (p->dr==NULL) {
        p->inf=t->inf;
        x=t;
        t=t->st;
    }
    else
    maxst(p,t->dr);
}

void del(arbore *&p,int k)
{
    arbore *t;
    if (p->inf>k) del(p->st,k);
    else
    if (p->inf<k) del(p->dr,k);
    else
    if (p->st==NULL &&p->dr==NULL)
        p=NULL;
    else
        if (p->st==NULL) {
            t=p->dr;
            delete p;
            p=t;
        }
    else
        if (p->dr==NULL) {
            t=p->dr;
            delete p;
            p=t;
        }
    else maxst(p,p->st);
 }

arbore *t;
int n,i,x,ok;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        insert(t,x);
    }

    cin>>x;
    ok=0;
    search(t,x,ok);
    if (ok==1) cout<<"Da";
    else
    cout<<"Nu";
    cout<<'\n';

    x=findmax(t);
    cout<<x;

    cin>>k;
    del(t,k);

    return 0;
}
