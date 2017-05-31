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

void inordine (arbore *p)
{
    if (p==NULL) return;
    inordine(p->st);
    cout<<p->inf<<' ';
    inordine(p->dr);
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

    inordine(p);

    return 0;
}
