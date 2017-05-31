#include <iostream>
#include <cstring>

using namespace std;

int nr,i;
char s[100];

int main()
{
    cin>>s;
    nr=0;
    for (i=0;i<=strlen(s)-1;i++) {
        if (s[i]!=s[strlen(s)-i-1]) break;
        else
        nr++;
    }

    if (nr==strlen(s)) nr=nr-1;
    for (i=0;i<=nr-1;i++)
        cout<<s[i];

    return 0;
}
