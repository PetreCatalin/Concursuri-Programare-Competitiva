#include <fstream>

using namespace std;

ifstream f("pb.in");
ofstream g("pb.out");


struct nodu {
    int inf;
    nodu *st,*dr;
};

typedef struct nodu *nod;

    nod *p;
 int nr=0;

 int nrf(int niv,int k,nod p)
 {
     if (niv==k &&p->st==NULL &&p->dr==NULL) nr++;
     nrf(niv+1,k,p->st);
     nrf(niv+1,k,p->dr);
     return nr;
 }

void creare()
{
    int x;
    f>>x;
    if (x==0) return;
    else
    {
        p=new nod;
        p->inf=x;
        creare(p->st);
        creare(p->dr);
    }
}

int main()
{

    creare(p);
    g<<nr;


    f.close();
    g.close();

    return 0;
}
