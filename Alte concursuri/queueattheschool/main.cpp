#include <iostream>
#include <cstring>

using namespace std;

char s[55];
int n,t,i,j,minim;

int main()
{
    cin>>n>>t;
    cin>>s;
    for (i=0;i<=n-1;i++)
        if (s[i]=='B') {minim=i;break;}

    for (i=1;i<=t;i++) {
        j=minim;
        while (j<=n-2) {
            if (s[j]=='B' &&s[j+1]=='G') {
                s[j]='G';
                s[j+1]='B';
                j=j+2;
            }
            else
            j++;
        }
    }

    for (i=0;i<=n-1;i++)
        cout<<s[i];

    return 0;
}
