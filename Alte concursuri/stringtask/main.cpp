#include <iostream>
#include <cstring>

using namespace std;

char s[105];
int i;

int main()
{
    cin>>s;
    for (i=0;i<=strlen(s)-1;i++)
        if (strchr("AEIOUYaeiouy",s[i])==NULL) {
            cout<<'.';
            if (s[i]>='A' &&s[i]<='Z') s[i]=s[i]+32;
            cout<<s[i];
        }
    return 0;
}
