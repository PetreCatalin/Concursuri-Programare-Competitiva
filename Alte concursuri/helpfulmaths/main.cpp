#include <iostream>
#include <cstring>

using namespace std;

char s[105];
int i,j,v[4];

int main()
{
    cin>>s;
    for (i=0;i<=strlen(s)-1;i=i+2)
        v[s[i]-'0']++;

    for (j=1;j<=v[1]-1;j++)
        cout<<'1'<<'+';
        if (v[1]!=0)
        {   cout<<'1';
            if (v[2]!=0 ||v[3]!=0) cout<<'+';
        }

    for (j=1;j<=v[2]-1;j++)
        cout<<'2'<<'+';
        if (v[2]!=0)
        {   cout<<'2';
            if (v[3]!=0) cout<<'+';
        }

    for (j=1;j<=v[3]-1;j++)
        cout<<'3'<<'+';
        if (v[3]!=0) cout<<'3';

    return 0;
}
