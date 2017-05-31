#include <fstream>

using namespace std;

int s,s1,i,j,a[7],v[7],n;
bool ok1,ok2;

int main()
{
    ifstream f("subms.in");
    ofstream g("subms.out");
    f>>s;
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i];
    ok1=true;
    while (ok1==true) {
           ok1=false;
           for (i=1;i<=n;i++) {
           if ((1+v[i])%2==0) v[i]=0;
           else
           if ((1+v[i])%2==1) {v[i]=1;break;}
           }
           s1=0;
           for (i=1;i<=n;i++)
           if (v[i]==1)
           s1=s1+a[i];
           if (s1==s) {
                  for (i=1;i<=n;i++)
                  if (v[i]==1)
                  g<<a[i]<<' ';
                  g<<'\n';
           }
           for (i=1;i<=n;i++)
                  if (v[i]!=1) {ok1=true;break;}
    }
    f.close();
    g.close();
    return 0;
}
