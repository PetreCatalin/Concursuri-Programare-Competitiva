#include <iostream>
#include <vector>

using namespace std;

#define MOD 666013

vector <long> h[666015];
long n,x,i,j,loc,ok;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>x;
        loc=x%MOD;
        ok=0;
        for (j=0;j<h[loc].size();++j)
            if (h[loc][j]==x) {ok=1;break;}
        if (ok==0) h[loc].push_back(x);
        if (ok==1) {cout<<"DA";break;}
    }

    if (ok==0) cout<<"NU";
    return 0;
}
