#include <iostream>
#include <cstdio>

using namespace std;

long n,i,a[30],ok;
char c;

int main()
{
    cin>>n;
    for (i=0;i<=n-1;++i) {
        cin>>c;
        if (c>='A' &&c<='Z') c=c+32;
        a[c-'a'+1]++;
    }

    ok=1;
    for (i=1;i<=26;i++)
        if (a[i]==0) {ok=0;break;}

    if (ok==1) cout<<"YES";
    else
    cout<<"NO";
    return 0;
}
