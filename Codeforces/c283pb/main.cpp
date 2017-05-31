#include <iostream>
#include <cstring>

using namespace std;

char s[1005],s1[1005],s2[1005],x;
long n,i,nr,minim,j,v,q;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>x;
        v[i]=x-'0';
    }

    for (j=1;j<=n;++j)
        vmx[j]=9;

    for (i=1;i<=10;i++)
        for (j=1;j<=n;j++) {
            v[j]++;
            if (v[j]==10) v[j]=0;
        }

        for (j=1;j<=n;j++)
            if (v[j]==0) q.push(j);



    return 0;
}
