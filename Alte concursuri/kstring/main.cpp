#include <iostream>
#include <cstring>

using namespace std;

char s[1005],c;
int i,k,ok,v[30],j,t;

int main()
{
    cin>>k;
    cin>>s;
    ok=1;

    for (i=0;i<=strlen(s)-1;i++)
        v[s[i]-'a'+1]++;

    for (i=1;i<=26;i++)
        if (v[i]%k!=0) {ok=0;break;}

    if (ok==0) cout<<"-1";
    else {
        for (t=1;t<=k;t++)
        for (i=1;i<=26;i++)
            for (j=1;j<=v[i]/k;j++) {
                c='a'+i-1;
                cout<<c;
            }
        }

    return 0;
}
