#include <bits/stdc++.h>

using namespace std;

long n,m,inte[100002],exte[100002],i,nr,x,y,j;
vector <long> vi,ve;

int main()
{
    ifstream f("zeul.in");
    ofstream g("zeul.out");
    f>>n>>m;
    for (i=1;i<=m;++i) {
            f>>x>>y;
            ++exte[x];
            ++inte[y];
    }

    for (i=1;i<=n;++i) {
        if (inte[i]<exte[i]) {
                for (j=1;j<=exte[i]-inte[i];++j)
                    vi.push_back(i);
                nr+=exte[i]-inte[i];
        }
         if (inte[i]>exte[i]) {
                for (j=1;j<=inte[i]-exte[i];++j)
                    ve.push_back(i);
                nr+=inte[i]-exte[i];
        }
    }

    g<<nr/2<<'\n';
    for (i=0;i<nr/2;++i)
        g<<ve[i]<<' '<<vi[i]<<'\n';

    f.close();
    g.close();
    return 0;
}
