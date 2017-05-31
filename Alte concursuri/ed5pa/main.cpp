#include <bits/stdc++.h>

using namespace std;

long long ok,i,nr1,nr2,c1,c2;
char s1[1000005],s2[1000005];

int main()
{
    gets(s1);
    gets(s2);
    for (i=0;i<strlen(s1);++i)
        if (s1[i]!='0') break;
    nr1=i;

    for (i=0;i<strlen(s2);++i)
        if (s2[i]!='0') break;
    nr2=i;

    if (strlen(s1)-nr1>strlen(s2)-nr2) cout<<'>';
    else
    if (strlen(s2)-nr2>strlen(s1)-nr1) cout<<'<';
    else {
        while (ok==0 &&nr1<strlen(s1) &&nr2<strlen(s2)) {
                c1=s1[nr1]-'0';
                c2=s2[nr2]-'0';
                if (c1<c2) {cout<<'<';ok=1;break;}
                if (c1>c2) {cout<<'>';ok=1;break;}
                ++nr1;
                ++nr2;
        }
    if (ok==0) cout<<'=';
    }


    return 0;
}
