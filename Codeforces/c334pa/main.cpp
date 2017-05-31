#include <bits/stdc++.h>

using namespace std;

long long m[10],w[10],i,x,y;
double s;

int main()
{
    for (i=1;i<=5;++i)
        cin>>m[i];
    for (i=1;i<=5;++i)
        cin>>w[i];
    cin>>x>>y;

    for (i=1;i<=5;++i) {
        double k= (double) m[i]/250;
        k=1-k;
        k=k*i*500-50*w[i];
        s+=max((double) 0.3*i*500,(double) k);
    }

    s+=100*x;
    s-=50*y;

    cout<<floor(s);
    return 0;
}
