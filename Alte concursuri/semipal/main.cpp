#include <fstream>

using namespace std;

int sol[65],n,i,t,k,nr,r,j;

ifstream f("semipal.in");
ofstream g("semipal.out");

void back(int k)
{
    int i;
    if(k==n+1) {
        if (sol[1]==sol[n]) {
        ++nr;
        if (nr==r) {
         for (i=1;i<=n;++i)
            if (sol[i]==0) g<<'a';
            else
            g<<'b';
        g<<'\n';
        return;
     }
    }
    }
     else
      {
      sol[k]=-1;
      while (sol[k]<1) {
          sol[k]++;
          back(k+1);
        }
      }
}


int main()
{
    f>>t;
    for (i=1;i<=t;++i) {
        f>>n>>r;
        nr=0;
        back(1);
        for (j=1;j<=n;++j)
            sol[j]=0;
    }

    f.close();
    g.close();
    return 0;
}
