#include <fstream>

using namespace std;

typedef struct {     int g,c;
                     double m;
}nume;

int i,G,n,j;
double s,x;
nume a[100],aux;

int main()
{
       ifstream f("grr.in");
       ofstream g("grr.out");
       f>>G>>n;
       for (i=1;i<=n;i++)
              f>>a[i].g;
       for (i=1;i<=n;i++) {
              f>>a[i].c;
              a[i].m=(double)a[i].c/a[i].g;
       }
       for (i=1;i<=n-1;i++)
              for (j=i+1;j<=n;j++)
              if (a[i].m<a[j].m) {
                     aux=a[i];
                     a[i]=a[j];
                     a[j]=aux;
              }
       s=0;
       for (i=1;i<=n;i++) {
              if (G==0) break;
              if (a[i].g<=G) {G=G-a[i].g;s=s+a[i].c;}
              else
              if (a[i].g>G) {;x=(double)G/a[i].g*a[i].c;s=s+x;G=0;}
       }
       g<<s;
       f.close();
       g.close();
    return 0;
}
