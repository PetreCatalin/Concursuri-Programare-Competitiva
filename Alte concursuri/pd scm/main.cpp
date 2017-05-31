#include <fstream>

using namespace std;

long int a[10000000],lung[10000000],i,maxim,j,poz,n;

int main()
{
   ifstream f("scmax.in");
   ofstream g("scmax.out");
   f>>n;
   for (i=1;i<=n;i++)
   f>>a[i];
   lung[n]=1;
   for (i=n-1;i>=1;--i) {
       maxim=0;
       for (j=i+1;j<=n;j++)
        if (a[i]<a[j]) if(maxim<lung[j]) maxim=lung[j];
   lung[i]=maxim+1;
   }

   maxim=lung[1];
   poz=1;
   for (i=2;i<=n;i++)
        if (maxim<lung[i]) {
            maxim=lung[i];
            poz=i;
        }
    g<<maxim<<'\n';
    g<<a[poz]<<' ';
    for (i=poz+1;i<=n;i++)
        if (lung[i]==maxim-1 && a[i]>=a[poz]) {
            g<<a[i]<<' ';
            poz=i;
            --maxim;
        }
    f.close();
    g.close();
    return 0;
}
