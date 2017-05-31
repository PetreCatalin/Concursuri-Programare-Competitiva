#include <fstream>
#include <cmath>

using namespace std;
int a[100],b[100],c[100],i,j,nr1,nr2,nr,aux,n,x,ac;

bool prim (int x)
    {
        int i;
        bool ok;
        ok=true;
        for (i=2;i<=x/2;i++) {
            if (x % i==0) ok=false;
            if (ok==false) break;
        }
    return ok;
    }

int main()
{
    ifstream f("control.in");
    ofstream g("control.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i];
    for (i=1;i<=n-1;i++)
        for (j=i+1;j<=n;j++)
        if (a[i]>a[j]) {
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            }
    x=0;
    i=0;
    while (i<n) {
        i++;
        if (i>n) break;
        x++;
        ac=a[i];
        nr=1;
        while (a[i+1]==ac) {
            i++;
            if (i>n) break;
            nr++;
        }
    b[x]=nr;
    }
    x=x-x % 3;
    i=0;
    while (i<x/3) {
        i++;
        nr1=0;
        nr2=0;
    if (b[i*3-2]%2==0) nr1++;
    else nr2++;
    if (b[i*3-1]%2==0) nr1++;
    else nr2++;
    if (b[i*3]%2==0) nr1++;
    else nr2++;
    if (nr1==3 || nr2==3) c[i]=1;
    else c[i]=0;
    }
    nr1=0;nr2=0;
    for (j=1;j<=i;j++) {
        if (c[j]==1) nr1++;
        if (c[j]==0) nr2++;
    }
     nr=nr1*10+nr2;
     g<<nr;
     g<<'\n';
     if (prim(nr)) g<<'1';
     else g<<'0';

     f.close();
     g.close();

    return 0;
}
