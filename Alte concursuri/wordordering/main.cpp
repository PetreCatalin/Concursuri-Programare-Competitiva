#include <bits/stdc++.h>

using namespace std;

long i,n,j;
map<char,int> m;

char a[30];
string s[100005];

inline bool cmp(string s1,string s2)
{
    long i=0;
    while (i<s1.length() &&i<s2.length()) {
            if (m[s1[i]]<m[s2[i]]) return true;
            else
            if (m[s1[i]]>m[s2[i]]) return false;
            ++i;
    }
    if (i==s1.length()) return true;
    else
    return false;
}

int main()
{
    cin>>a;
    cin>>n;

    for (i=1;i<=n;++i)
        cin>>s[i];

    for (i=0;i<strlen(a);++i) {
        m[a[i]]=0+i;
        m[a[i]-32]=30+i;
    }

    sort(s+1,s+n+1,cmp);

    for (i=1;i<=n;++i)
        cout<<s[i]<<'\n';

    return 0;
}
