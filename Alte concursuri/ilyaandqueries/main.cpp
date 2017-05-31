#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[100003];
long i,v[100003],m,l,r,nr;

int main()
{
    gets(s);
    cin>>m;
    v[0]=0;
    nr=strlen(s)-1;
    for (i=0;i<nr;++i) {
        v[i+1]=v[i];
        if (s[i]==s[i+1]) ++v[i+1];
    }

    for (i=1;i<=m;++i) {
            cin>>l>>r;
            cout<<v[r-1]-v[l-1]<<'\n';
    }
    return 0;
}
