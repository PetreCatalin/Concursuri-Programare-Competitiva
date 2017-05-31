#include <iostream>
#include <cstring>

using namespace std;

long m,i,nr,x,j,v[200005];
char s[200005];

int main()
{
    cin>>s;
    nr=strlen(s);
    cin>>m;
    for (i=1;i<=m;++i) {
            cin>>x;
            for (j=x;j<=nr/2;++j)
                if (v[j]==0) v[j]=1;
                else
                v[j]=0;
    }

    for (i=1;i<=nr/2;++i)
        if (v[i]%2==0)
            cout<<s[i-1];
        else
        cout<<s[nr-i];

    for (i=nr/2+1;i<=nr;++i)
        if (v[nr-i+1]==0)
            cout<<s[i-1];
        else
        cout<<s[nr-i];

    return 0;
}
