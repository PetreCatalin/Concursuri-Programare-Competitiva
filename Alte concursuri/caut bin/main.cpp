#include <fstream>

using namespace std;

int a[100],i,n,x,poz,st,dr,mij;

int main()
{
    ifstream f("cb.in");
    ofstream g("cb.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i];
    f>>x;
    st=1;dr=n;poz=0;
    while (st<=dr && poz==0) {
        mij=(st+dr)/2;
        if (a[mij]==x) poz=mij;
        if (a[mij]<x) st=mij+1;
        if (a[mij]>x) dr=mij-1;
    }
    if (poz==0) g<<"nu exista";
    if (poz!=0) g<<"e pe pozitia "<<poz;
    f.close();
    g.close();
    return 0;
}

//se foloseste doar ptr vectori ordonati;
//st=1;dr=n; se cauta tot timpul mijlocul pana se gaseste sau stanga devine mai mare ca dreapta;
//daca mij=numarul s-a gasit daca nu comparam mij cu numarul si cautam ori in jumata din stanga ori in dreapta;
//daca poz ramane 0 nu exista numarul altfel poz e pozitita pe care se afla
