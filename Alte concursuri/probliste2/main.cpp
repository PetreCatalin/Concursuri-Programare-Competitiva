#include <fstream>
#include <cmath>

using namespace std;


struct point{
       int inf;
       point *leg;
};

void stergere (point *&p)
{
       point *q;
       q=p;
       p=p->leg;
       delete q;
}

void inserare (point *p)
{
       point *nou,*t;
       t=p;
       nou=new point;
       nou->inf=0;
       nou->leg=t->leg;
       t->leg=nou;

}


int j,n,i,nr,x,ap[100],maxim,maxim2,fib[20];
point *p,*u,*q,*t;
bool ok;

int main()
{
       ifstream f("liste2.in");
       ofstream g("liste2.out");
       f>>n;
       f>>j;
       p=new point;
       p->leg=NULL;
       p->inf=j;
       u=p;
       ap[j]++;
       if (j>maxim) maxim=j;
       for (i=2;i<=n;i++) {
              f>>j;
              q=new point;
              q->inf=j;
              ap[j]++;
              if (j>maxim) maxim=j;
              q->leg=NULL;
              u->leg=q;
              u=q;
       }
q=p;
while (q){
    g<<q->inf<<' ';
    q=q->leg;
}
g<<'\n';

    q=p;
       while (q)
       {      nr=0;
              x=q->inf;
              while (x!=0) {
              nr=nr+x %10;
              x=x/10;
              }
              if (nr%2==0) g<<q->inf<<' ';
       q=q->leg;
       }
g<<'\n';

for (i=1;i<=maxim;i++)
       if (ap[i]>maxim2) maxim2=ap[i];
       q=p;
       while (q) {
              if (ap[q->inf]==maxim2) inserare(q);
              q=q->leg;
       }
q=p;
while (q){
    g<<q->inf<<' ';
    q=q->leg;
}
g<<'\n';

/*
q=p;
while (q) {
       if (sqrt(q->inf)==trunc(sqrt(q->inf))) stergere(q);
       q=q->leg;
}
q=p;
while (q){
    g<<q->inf<<' ';
    q=q->leg;
}
g<<'\n';

fib[1]=1;
fib[2]=1;
for (i=3;i<=20;i++)
fib[i]=fib[i-2]+fib[i-1];

q=p;
while (q) {
       ok=false;
       for (i=2;i<=20;i++)
       if (fib[i]==q->inf) {ok=true;break;}
       if (ok) stergere (q);
       q=q->leg;
}
q=p;
while (q){
    g<<q->inf<<' ';
    q=q->leg;
}
g<<'\n';
*/
       f.close();
       g.close();
    return 0;
}
