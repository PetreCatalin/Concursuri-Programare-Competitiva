#include <bits/stdc++.h>

using namespace std;

long long n,s,i,c,sol;

struct nume{
    int x,y;
};

inline bool cmp(nume a,nume b){
    return a.x<b.x;
}

nume a[1005];

int main()
{

    cin>>n>>s;

    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;

    sort(a+1,a+n+1,cmp);

    c=s,sol=0;
    for(i=n;i>=1;i--) {
            if(c>a[i].x) {
                sol+=c-a[i].x;
                c=a[i].x;
            }

            if(sol<a[i].y) sol=a[i].y;
    }

    sol=sol+c;
    cout<<sol;

    return 0;
}
