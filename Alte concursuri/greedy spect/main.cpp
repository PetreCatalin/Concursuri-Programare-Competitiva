#include <fstream>

using namespace std;

int n,a[100],b[100],nr,maxim,i,j,aux;
bool ok;

int main()
{
    ifstream f("grsp.in");
    ofstream g("grsp.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i]>>b[i];
    for (i=1;i<=n-1;i++)
       for (j=i+1;j<=n;j++)
       if (b[i]>b[j]) {
              aux=a[i];
              a[i]=a[j];
              a[j]=aux;
              aux=b[i];
              b[i]=b[j];
              b[j]=aux;
       }
       nr=1;
       maxim=b[1];
       i=2;
       ok=true;
       while (ok==true) {
              ok=false;
              for (j=i;j<=n;j++)
              if (a[j]>=maxim) {maxim=b[j];i=j;nr++;ok=true;break;}
       }
       g<<nr;
       f.close();
       g.close();
       return 0;
}
