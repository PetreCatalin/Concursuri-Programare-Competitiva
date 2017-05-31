#include <iostream>
#include <cstring>

using namespace std;

char s[105];
int i,nr;

int main()
{
    cin>>s;
    if (s[0]>='a' &&s[0]<='z') {
        for (i=1;i<=strlen(s)-1;i++)
            if (s[i]>='A' &&s[i]<='Z') nr++;
        if (nr==strlen(s)-1) {
            for (i=1;i<=strlen(s)-1;i++)
            s[i]=s[i]+32;
            s[0]=s[0]-32;
            cout<<s;
        }
        else
        cout<<s;
    }

    else
    {
    for (i=0;i<=strlen(s)-1;i++)
        if (s[i]>='A' &&s[i]<='Z') nr++;
    if (nr!=strlen(s)) cout<<s;
        else {
        for (i=0;i<=strlen(s)-1;i++)
        s[i]=s[i]+32;
        cout<<s;
        }
    }

    return 0;
}
