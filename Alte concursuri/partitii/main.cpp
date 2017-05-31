#include <fstream>

using namespace std;

int i,j,n,k,st[6],maxim;
bool ok;

int main()
{
    ifstream f("partitii.in");
    ofstream g("partitii.out");
    f>>n;
    k=1;
    while (k>0) {
        if (st[k]<k) st[k]++;
        if (st[n]!=0) {
            maxim=0;
            for (i=1;i<=n;i++)
            if (st[i]>maxim) maxim=st[i];
            ok=false;
            for (i=0;i<=n;i++)
            if (st[i]==maxim-1) {ok=true;break;}
            if (ok==true) {
            for (j=1;j<=maxim;j++) {
            for (i=1;i<=n;i++) {
                if (st[i]==j)
                g<<i<<' ';
            }
            g<<' '<<' ';
            }
            g<<'\n';
        }
        }
            if (k<n) {if (st[k+1]!=k)  {k++;st[k]=0;}
                      else
                      if (st[k+1]==k) --k;}
            else
            if (st[k]==k) {
                            do
                            {if (k<=0 &&st[k]==0) break;
                            st[k]=0;--k;}
                            while (st[k]>=k);

            }
        }
    f.close();
    g.close();
    return 0;
}
