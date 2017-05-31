#include <iostream>
#include <cstring>

using namespace std;

char s[100005];
long nr1,i,nr2,v1[100005],v2[100005],nr,ramas,ap,ok,x;

int main()
{
    cin>>s;
    nr=strlen(s)-1;
    for (i=0;i<=nr;++i) {
        if (s[i]=='(') {++nr1;v1[i]=nr1;v2[i]=nr2;}
        if (s[i]==')') {++nr2;v2[i]=nr2;v1[i]=nr1;}
        if (s[i]=='#') {++ap;v1[i]=nr1;++nr2;v2[i]=nr2;}
        if (nr1<nr2) {ok=1;break;}
    }


        if (ok==1) cout<<"-1";
        else {
            for (i=nr;i>=0;--i)
                if (s[i]==')') {
                    ramas=v1[i]-v2[i];
                    break;
                }
            for (i=0;i<=nr;++i)
                if (s[i]=='#') {
                    x=v1[i]-v2[i];
                    if (x>ramas)
                        x=ramas;
                    ramas=ramas-x;
                    ++x;
                    cout<<x<<'\n';
                }
        }

    return 0;
}
