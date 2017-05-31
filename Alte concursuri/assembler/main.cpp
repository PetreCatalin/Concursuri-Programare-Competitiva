#include <iostream>
#include <cstring>

using namespace std;

char s[10];
long long i,nr,n,su,x;

int main()
{
    while (!cin.eof()) {
            cin>>s;
            n=0;
            su=1;
            nr=strlen(s)-1;
            for (i=nr;i>=0;--i) {
                if (s[i]>='0' &&s[i]<='9') x=s[i]-'0';
                if (s[i]=='A') x=10;
                if (s[i]=='B') x=11;
                if (s[i]=='C') x=12;
                if (s[i]=='D') x=13;
                if (s[i]=='E') x=14;
                if (s[i]=='F') x=15;
                n+=su*x;
                su*=16;
            }
            cout<<n<<'\n';
    }
    return 0;
}
