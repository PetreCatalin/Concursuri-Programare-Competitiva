#include <iostream>
#include <vector>

using namespace std;

#define mod 666013

vector <long long> v[666015];
long long n,i,a[300005],nr,ok,j;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>a[i];
        nr=a[i]%mod;
        if (v[nr].size()==0) {
            v[nr].push_back(a[i]);
            cout<<a[i]<<' ';
        }
        else {
            ok=1;
            while (ok==1) {
                ++a[i];
                nr=a[i]%mod;
                ok=0;
                for (j=0;j<v[nr].size();++j)
                    if (v[nr][j]==a[i]) {ok=1;break;}
            }
            v[nr].push_back(a[i]);
            cout<<a[i]<<' ';
        }
    }

    return 0;
}
