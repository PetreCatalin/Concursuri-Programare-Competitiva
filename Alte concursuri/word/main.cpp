#include <iostream>
#include <cstring>

using namespace std;

char s[105];
int nr1,nr2,i;

int main()
{
    cin>>s;
    for (i=0;i<=strlen(s)-1;i++)
        if (s[i]>='a' &&s[i]<='z') nr1++;
        else
        nr2++;

    if (nr1>=nr2)
        for (i=0;i<=strlen(s)-1;i++) {
        if (s[i]>='A' &&s[i]<='Z') s[i]=s[i]+32;
        cout <<s[i];
    }
    else
        for (i=0;i<=strlen(s)-1;i++) {
        if (s[i]>='a' &&s[i]<='z') s[i]=s[i]-32;
        cout<<s[i];
        }

    return 0;
}
