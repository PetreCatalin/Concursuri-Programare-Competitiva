#include <iostream>
#include <cstring>

using namespace std;

char s[10][110],c;
long nr[10],maxim,minim,pm,pmin,ok,i,ok1;

int main()
{
    for (i=1;i<=4;i++)
    cin>>s[i];

    maxim=-1;
    minim=105;

    for (i=1;i<=4;i++) {
    nr[i]=strlen(s[i])-2;
    if (nr[i]>maxim) {maxim=nr[i];pm=i;}
    if (nr[i]<minim) {minim=nr[i];pmin=i;}
    }

    ok=1;
    for (i=1;i<=4;i++)
        if (pm!=i) {
            if (maxim>=nr[i]*2) ok=1;
            else
            {ok=0;break;}
        }

    ok1=1;
    for (i=1;i<=4;i++)
        if (pmin!=i) {
            if (minim*2<=nr[i]) ok1=1;
            else
            {ok1=0;break;}
        }

    if (ok==1 &&ok1==1) cout<<'C';
    else
    if (ok==1) {c='A'+pm-1;cout<<c;}
    else
    if (ok1==1) {c='A'+pmin-1;cout<<c;}
    else
    cout<<'C';

    return 0;
}
