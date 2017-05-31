#include <bits/stdc++.h>

using namespace std;

long long i,n,v[5005],d[5005],p[5005],nr,j,k,viz[5005],t,maxim;
vector <int> a;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i)
        cin>>v[i]>>d[i]>>p[i];

    for (i=1;i<=n;++i)
        if (p[i]>=0 &&viz[i]==0) {
                ++nr;a.push_back(i);//cout<<i<<' '<<p[i]<<' ';

                t=i+1;
                for (j=v[i];j>=1;--j) {
                    while (viz[t]==1 &&t<n) ++t;
                    if (p[t]-j<0)  {p[t]=-1;if (t>maxim) maxim=t;}
                    else
                    p[t]-=j;
                    ++t;
                    if (t==n+1) break;
                }

                for (j=i+1;j<=maxim;++j)
                    if (p[j]<0 &&viz[j]==0) {
                            viz[j]=1;
                         for (k=j+1;k<=n;++k)
                            if (viz[k]==0 &&p[k]>=0)
                               if (p[k]-d[j]<0) {p[k]=-1;if (k>maxim) maxim=k;}
                               else
                               p[k]-=d[j];
                    }
        }

    cout<<nr<<'\n';
    for (i=0;i<nr;++i)
        cout<<a[i]<<' ';
    return 0;
}
