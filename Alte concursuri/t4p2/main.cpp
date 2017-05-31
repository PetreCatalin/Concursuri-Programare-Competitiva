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

void pop(nod *varf)
{
    if (varf!=NULL) {
        nod *c=varf;
        varf=varf->urm;
        delete c;
    }
}

int n,i,nr,poz;
char c;

int main()
{
    cin>>n;
    nod *varf=new nod;
    cin>>c;
    if (c=='a') nr=1;
    else
    nr=2;

    varf->inf=nr;
    varf->urm=NULL;
    poz=1;

    for (i=2;i<=n;i++)
    {
        cin>>c;
        if (nr==1) {
            if (c=='a') {push(1,varf);poz++;}
            else
            {
                if (poz==0) {
                    push(2,varf);
                    poz=1;
                    nr=2;
                }
                else
                {pop(varf);poz=poz-1;}
            }
        }
        else
        if (nr==2) {
            if (c=='b') {push(2,varf);poz++;}
            else {
                if (poz==0) {
                    push(1,varf);
                    poz=1;
                    nr=1;
                }
                else
            {pop(varf);poz=poz-1;}
            }
        }
    }

    if (poz==0) cout<<"Da";
    else
    cout<<"Nu";

    return 0;
}
