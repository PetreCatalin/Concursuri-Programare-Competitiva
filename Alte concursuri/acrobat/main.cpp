#include <fstream>

using namespace std;

long long n,s,i,fort[50005],minim,maxim;
long m[50005],poz,nr;
int viz[50005];

int main()
{
    ifstream f("acrobat.in");
    ofstream g("acrobat.out");
    f>>n;
    for (i=1;i<=n;i++) {
        f>>m[i]>>fort[i];
        s=s+m[i];
    }

    maxim=-500000005;
    while (nr<=n-2) {
          nr++;
          minim=500000005;
          for (i=1;i<=n;i++)
            if (s-m[i]-fort[i]<minim &&viz[i]==0) {minim=s-m[i]-fort[i];poz=i;}
          viz[poz]=1;s=s-m[poz];
          if (minim>maxim) maxim=minim;
    }

    g<<maxim;

    f.close();
    g.close();
    return 0;
}
