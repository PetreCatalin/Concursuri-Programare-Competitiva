#include <iostream>

using namespace std;

struct nod {
    int inf;
    nod *urm;
};

void push(int a,nod *&varf)
{
    nod *q=new nod;
    q->inf=a;
    q->urm=varf;
    varf=q;
}

int pop(nod *varf)
{
    if (varf!=NULL) {
        int x=varf->inf;
        nod *c=varf;
        varf=varf->urm;
        delete c;
        return x;
    }
}

void peek(nod *varf)
{
    cin>>varf->inf;
}

int empty(nod *varf)
{
    if (varf==NULL) return 1;
    else
    return 0;
}

int search(int a,nod *varf)
{
    int nr,ok;
    nr=0; ok=0;
    while (varf!=NULL) {
        if (varf->inf==a) {ok=1;return nr;}
        nr++;
        varf=varf->urm;
    }
    if (ok==0) return -1;
}

void afiseaza(nod *varf)
{
    while (varf!=NULL) {
        cout<<varf->inf<<' ';
        varf=varf->urm;
    }
}

int n,i,a,nr,ok;

int main()
{
    cin>>n;
    nod *varf=new nod;
    cin>>varf->inf;
    varf->urm=NULL;

    for (i=2;i<=n;i++) {
        cin>>a;
        push(a,varf);
    }

   /* nr=pop(varf);
    cout<<nr<<'\n'; */

    ok=empty(varf);
    if (ok==1) cout<<"stiva e vida"<<'\n';
    else
    cout<<"stiva nu e vida"<<'\n';

    cin>>a;
    nr=search(a,varf);
    cout<<nr<<'\n';

    afiseaza(varf);

    return 0;
}
