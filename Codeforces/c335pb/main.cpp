#include <bits/stdc++.h>

using namespace std;

long long x,y,n,m,i,j,a[505][505],p,i1,i2;
char s[100005];

int main()
{
    cin>>n>>m>>x>>y;
    cin>>s;
    a[x][y]=1;p=n*m-1;
    cout<<"1 ";

    for (i=0;i<=n+1;++i) {
        a[i][0]=-1;
        a[i][m+1]=-1;
    }

    for (i=0;i<=m+1;++i) {
        a[0][i]=-1;
        a[n+1][i]=-1;
    }

    for (i=0;i<strlen(s)-1;++i) {

            if (s[i]=='U') {
                    if (a[x-1][y]==0) {
                            a[x-1][y]=1;
                            cout<<"1 ";
                            --x;
    if (p>0) --p;
                    }
                    else {
                    if (a[x-1][y]==1) --x;
                    cout<<"0 ";
                    }
            }

              if (s[i]=='D') {
                    if (a[x+1][y]==0) {
                            a[x+1][y]=1;
                            cout<<"1 ";
                            ++x;if (p>0) --p;
                    }
                    else {
                    if (a[x+1][y]==1) ++x;
                    cout<<"0 ";
                    }
              }

               if (s[i]=='L') {
                    if (a[x][y-1]==0) {
                            a[x][y-1]=1;
                            cout<<"1 ";
                            --y;if (p>0) --p;
                    }
                    else {
                    if (a[x][y-1]==1) --y;
                    cout<<"0 ";
                    }
            }

              if (s[i]=='R') {
                    if (a[x][y+1]==0) {
                            a[x][y+1]=1;
                            cout<<"1 ";
                            ++y;if (p>0) --p;
                    }
                    else {
                    if (a[x][y+1]==1) ++y;
                    cout<<"0 ";
                    }
              }
    }

    int nr=strlen(s)-1;
    if (s[nr]=='U' &&a[x-1][y]!=-1) --x;
    if (s[nr]=='D' &&a[x+1][y]!=-1) ++x;
    if (s[nr]=='L' &&a[x][y-1]!=-1) --y;
    if (s[nr]=='R' &&a[x][y+1]!=-1) ++y;
    cout<<p;

    return 0;
}

