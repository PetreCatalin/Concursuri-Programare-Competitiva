#include <fstream>

using namespace std;

long n,w,a,b[50005],i,j,ok,nr,viz[1000005],maxim;

int main()
{
    ifstream f("skyline.in");
    ofstream g("skyline.out");
    f>>n>>w;
    for (i=1;i<=n;i++) {
        f>>a>>b[i];
        if (b[i]==0) {
            for (j=1;j<=maxim;j++)
                if (viz[j]==1) viz[j]=0;
            maxim=0;
        }
        else
        {
            if (b[i]>maxim) maxim=b[i];
            if (viz[b[i]]==0) {viz[b[i]]=1;nr++;}
            else {
            if (b[i]!=1) {
                j=i-1;ok=1;
                while (b[j]!=b[i]) {
                    if (b[j]<b[i]) {ok=0;break;}
                    j=j-1;
                }
                if (ok==0) nr++;
                }
            }
        }
    }

    g<<nr;

    f.close();
    g.close();
    return 0;
}
