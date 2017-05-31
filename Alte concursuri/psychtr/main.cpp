#include <bits/stdc++.h>

using namespace std;

char v[505];
int i,x,y,n,m;

int main()
{
    ifstream f("psychtraining.in");
    ofstream g("psychtraining.out");
    f>>n>>m;
    f>>x>>y;
    v[x]='a';v[y]='b';
    for (i=2;i<=m;++i) {
            f>>x>>y;
            if (v[x]=='a') v[y]='b';
            else
            if (v[x]=='b') v[y]='a';
            else
            if (v[y]=='a') v[x]='b';
            else
            if (v[y]=='b') v[x]='a';
    }
    g<<'1'<<'\n';
    for (i=1;i<=n;++i)
        g<<v[i];

    f.close();
    g.close();
    return 0;
}
