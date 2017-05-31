#include <bits/stdc++.h>

using namespace std;

long long nr;
char s[100],x;

int main()
{
    gets(s);
    x=s[strlen(s)-1];
    if (x=='k') {
            nr=s[0]-'0';
            if (nr==5 ||nr==6) cout<<"53";
            else
            cout<<"52";
    }
    else {
        nr=s[0]-'0';
        if (s[1]>='0' &&s[1]<='9') nr=nr*10+(s[1]-'0');
        if (nr==31) cout<<'7';
        else
        if (nr==30) cout<<"11";
        else
        cout<<"12";
    }


    return 0;
}
