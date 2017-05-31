#include <iostream>
#include <cstring>

using namespace std;


struct string{
    char s[105];
}a[105];

long v,n,m,i,nr,j;
char maxim;

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;++i)
        cin>>a[i].s;

    nr=0;
    while (nr<m) {
        maxim='a';
    for (i=1;i<=n;++i) {
        if (a[i].s[nr]>=maxim) maxim=a[i].s[nr];
        else {
            if (a[i].s[0]<a[i-1].s[nr] || nr==0) {
            ++v;
            for (j=1;j<=n;++j)
                strcpy(a[j].s+i,a[j].s+i+1);
                --m;
            --nr;
            break;
        }
        }
    }
    ++nr;
    }

    cout<<v;

    return 0;
}
