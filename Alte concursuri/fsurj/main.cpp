#include <fstream>

using namespace std;

int i,n,m,k,v[6],st[6],c;

int main()
{
    ifstream f("fsurj.in");
    ofstream g("fsurj.out");
    f>>n;
    f>>m;
    k=1;
    while (k>0) {
        if (st[k]<m) st[k]++;
        if (st[n]!=0) {
            c=1;
            for (i=1;i<=n;i++)
            if (v[i]!=0) v[i]=0;
            for (i=1;i<=n;i++)
            v[st[i]]=1;
            for (i=1;i<=m;i++)
            if (v[i]==0) {c=0;break;}
            if (c==1) {
            for (i=1;i<=n;i++) {
                g<<i<<' '<<st[i];
                g<<'\n';
            }
            g<<'\n';
        }
        }
            if (k<n) {if (st[k+1]!=m)  {k++;st[k]=0;}
                      else
                      if (st[k+1]==m) --k;}
            else
            if (st[k]==m) { do
                            {st[k]=0;--k;}
                            while (st[k]==m);
            }
        }
    f.close();
    g.close();
    return 0;
}
