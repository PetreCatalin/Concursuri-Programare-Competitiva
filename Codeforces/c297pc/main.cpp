#include <iostream>
#include <algorithm>

using namespace std;

inline bool cmp(long long a,long long b)
{
    return a>b;
}

long long v[100005],i,n;
long long s;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i)
        cin>>v[i];

    sort (v+1,v+n+1,cmp);

    i=1;
    while (i<=n-3) {
        if (v[i]==v[i+1] &&v[i+2]==v[i+3]) {
            s+=v[i]*v[i+2];
            i+=4;
        }
        else
        if (v[i]==v[i+1]+1 &&v[i+2]==v[i+3]) {
            s+=v[i+1]*v[i+2];
            i+=4;
        }
        else
        if (v[i]==v[i+1]+1 &&v[i+2]==v[i+3]+1) {
                s+=v[i+1]*v[i+3];
                i+=4;
        }
        else
         if (v[i]==v[i+1] &&v[i+2]==v[i+3]+1) {
            s+=v[i+1]*(v[i+2]-1);
            i+=4;
         }
        else
        ++i;
    }

    cout<<s;

    return 0;
}
