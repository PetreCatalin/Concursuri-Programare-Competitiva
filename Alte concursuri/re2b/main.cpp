#include <bits/stdc++.h>

using namespace std;

long long n,m,x,nr1,nr2,i,b[200005];
vector <long long> a;

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;++i) {
        cin>>x;
        a.push_back(x);
    }
    for (i=1;i<=m;++i) {
        cin>>b[i];
    }

    sort(a.begin(),a.end());

    vector <long long>::iterator low,up;
    for (i=1;i<=m;++i) {
            low=std::lower_bound (a.begin(), a.end(),b[i]);
            up= std::upper_bound (a.begin(), a.end(),b[i]);
            nr1=low-a.begin();
            nr2=up-a.begin()+1;
            if (nr1+1==nr2) cout<<nr1<<' ';
            else
            cout<<nr2-1<<' ';
    }

    return 0;
}
