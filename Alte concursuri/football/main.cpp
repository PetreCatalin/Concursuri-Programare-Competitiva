#include <iostream>
#include <cstring>

using namespace std;

char s[105];
int x,ok,y,i,nr;

int main()
{
    cin>>s;
    x=s[0]-'0'; ok=0; nr=1;
    for (i=1;i<=strlen(s)-1;i++) {
        y=s[i]-'0';
        if (x==y) {nr++; if (nr>=7) ok=1;}
        else
        {
            x=y;
            nr=1;
        }
    }

    if (ok==1) cout<<"YES";
    else
    cout<<"NO";

    return 0;
}
