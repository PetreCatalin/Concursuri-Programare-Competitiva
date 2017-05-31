#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

char s[100005];
long nr,i,poz1,poz2,ok;

int main()
{
    gets(s);
    nr=strlen(s)-1;

    for (i=0;i<=nr-1;++i)
    if (s[i]=='A' &&s[i+1]=='B') {poz1=i+1;break;}
    for (i=nr-1;i>=0;--i)
    if (s[i]=='B' &&s[i+1]=='A') {poz2=i+1;break;}
    if (poz1!=0 &&poz2!=0)
            if (abs(poz1-poz2)>1) {ok=1;cout<<"YES";}

    if (ok==0) {
            poz1=0;poz2=0;
            for (i=0;i<=nr-1;++i)
            if (s[i]=='B' &&s[i+1]=='A') {poz1=i+1;break;}
            for (i=nr-1;i>=0;--i)
            if (s[i]=='A' &&s[i+1]=='B') {poz2=i+1;break;}
            if (poz1!=0 &&poz2!=0)
            if (abs(poz1-poz2)>1) {ok=1;cout<<"YES";}
    }

    if (ok==0) cout<<"NO";

    return 0;
}
