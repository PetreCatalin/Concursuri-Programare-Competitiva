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

char c;
int n,ok,i,nr1,nr2;

int main()
{
    ok=1;
    cin>>n;
    nod *varf=new nod;
    cin>>c;
    if (c=='(') {
        varf->inf=1;
        varf->urm=NULL;
        nr1=1;
    }
    else
     {cout<<'1';ok=0;}

     if (ok==1) {
         for (i=2;i<=n;i++) {
             cin>>c;
             if (c=='(') {nr1++;push(1,varf);}
             else {
             nr2++;
             if (nr2>nr1) {cout<<i;ok=0;break;}
                else push(2,varf);
             }
         }
     }

     if (ok==1) cout<<"sirul e parantezat corect";

    return 0;
}
