#include <fstream>

using namespace std;

int i,j,aux,n,m,p,u1,u2,x,nr,a[100],b[100],s;

int main()
{
       ifstream f("gm.in");
       ofstream g("gm.out");
       f>>n>>m>>x;
       for (i=1;i<=n;i++)
       f>>a[i];
       for (i=1;i<=m;i++)
       f>>b[i];
       for (i=1;i<=n-1;i++)
              for (j=i+1;j<=n;j++)
              if (a[i]<a[j]) {
                     aux=a[i];
                     a[i]=a[j];
                     a[j]=aux;
              }
       for (i=1;i<=m-1;i++)
              for (j=i+1;j<=m;j++)
              if (b[i]<b[j]) {
                     aux=b[i];
                     b[i]=b[j];
                     b[j]=aux;
              }
       s=0;nr=0;p=1;u1=n;u2=m;
       do {
              if (a[p]*b[p]>=a[u1]*b[u2]) {s=s+a[p]*b[p];p++;nr++;}
              else {s=s+a[u1]*b[u2];--u1;--u2;nr++;}
       }
       while (nr<x);
       g<<s;
       f.close();
       g.close();
    return 0;
}
