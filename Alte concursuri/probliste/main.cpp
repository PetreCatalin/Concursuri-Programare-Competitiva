#include <fstream>
#include <cmath>

using namespace std;


struct point{
       int inf;
       point *leg;
};

bool prim (int x)
{
       int i;
       bool ok;
       ok=true;
       if (x<2) ok=false;
       for (i=2;i<=trunc(sqrt(x));i++)
       if (x%i==0) {ok=false;break;}
       return ok;
}

void stergere (point *&p)
{
       point *q;
       q=p;
       p=p->leg;
       delete q;
}

void inserare (point *p,int y)
{
       point *nou,*t;
       t=p;
       nou=new point;
       nou->inf=y;
       nou->leg=t->leg;
       t->leg=nou;

}


int j,n,i;
point *p,*u,*q,*t;
bool ok;

int main()
{
       ifstream f("liste.in");
       ofstream g("liste.out");
       f>>n;
       f>>j;
       p=new point;
       p->leg=NULL;
       p->inf=j;
       u=p;
       for (i=2;i<=n;i++) {
              f>>j;
              q=new point;
              q->inf=j;
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
       while (q->leg)
       {
              int m;
              m= (q->inf+q->leg->inf)/2;
              inserare(q,m);
              q=q->leg->leg;
       }
q=p;
while (q){
    g<<q->inf<<' ';
    q=q->leg;
}
g<<'\n';
       q=p;
       while (q&&prim(q->inf))
       {
           stergere(q);


       }
       q=p;
       while(q->leg!=NULL){
           if (prim(q->leg->inf)) {
               t=q->leg;
               q->leg=t->leg;
               delete t;
           }
           else
           q=q->leg;
       }
       q=p;
       while (q)
       {
              g<<q->inf<<' ';
              q=q->leg;
       }

       f.close();
       g.close();
    return 0;
}
