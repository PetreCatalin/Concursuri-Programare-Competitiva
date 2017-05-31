#include <iostream>
#include <algorithm>

using namespace std;

struct nume{
    long x;
    long y;
}v[103];

long n,i,minim,nrpoz,nrneg;
long long s;

inline bool cmp(nume a,nume b)
{
    return a.x<b.x;
}

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>v[i].x>>v[i].y;
        if (v[i].x<0) ++nrneg;
        else
        ++nrpoz;
    }

    minim=min(nrneg,nrpoz);
    sort(v+1,v+n+1,cmp);

    if (minim==nrneg) {
            for (i=1;i<=minim;++i)
                s+=v[i].y;
                if (minim==nrpoz)
                    for (i=minim+1;i<=nrpoz*2;++i)
                    s+=v[i].y;
                else
                    for (i=minim+1;i<=minim+1+nrneg;++i)
                    s+=v[i].y;
    }
    else {
        for (i=nrneg+1;i<=n;++i)
                s+=v[i].y;
        for (i=nrneg;i>=nrneg-minim;--i)
                s+=v[i].y;
    }

    cout<<s;

    return 0;
}
