#include <iostream>
#include <cstring>

using namespace std;

struct st{
    char s[15];
} s1[3005],s2[3005];

long n,m,i,j,nr;
char st[15];

int main()
{
    cin>>n>>m;
    for (i=1;i<=m;++i) {
        cin>>s1[i].s;
        cin>>s2[i].s;
    }

    for (i=1;i<=n;++i) {
        cin>>st;
        for (j=1;j<=m;++j) {
            nr=strcmp(s1[j].s,st);
            if (nr==0) {
                if (strlen(s1[j].s)<=strlen(s2[j].s))
                    cout<<s1[j].s<<' ';
                else
                    cout<<s2[j].s<<' ';
                break;
            }
        }
    }

    return 0;
}
