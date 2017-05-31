#include <iostream>

using namespace std;

long n,i,ok,nr,nr1;
char s[10];

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>s;
        ok=0;
        nr=(s[0]-'0')*10+(s[1]-'0');
        nr1=(s[3]-'0')*10+(s[4]-'0');
        if (nr>=24 ||nr1>=60) {ok=1;cout<<"NO"<<'\n';}
        if (ok!=1) {
        ok=0;
        if (s[3]=='0' &&s[4]=='0') ok=1;
        else
        if (s[0]==s[3] &&s[1]==s[4]) ok=1;
        else
        if (s[0]==s[4] &&s[1]==s[3]) ok=1;
        else
        if (s[4]==s[3]+1 &&s[3]==s[1]+1 &&s[1]==s[0]+1) ok=1;
        else {
            nr=(s[0]-'0')*1000+(s[1]-'0')*100+(s[3]-'0')*10+(s[4]-'0');
            if (nr!=1) ok=1;
            while (nr!=1) {
                if (nr%2==1) {ok=0;break;}
                nr=nr/2;
            }
        }
        if (ok==1) cout<<"YES"<<'\n';
        else
        cout<<"NO"<<'\n';
        }
    }
    return 0;
}
