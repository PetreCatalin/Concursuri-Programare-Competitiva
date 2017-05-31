#include <iostream>
#include <cstdio>

using namespace std;

long t,i,n,m;

int main()
{
    cin>>t;
    for (i=1;i<=t;++i) {
        cin>>n>>m;
        cout<<"Scenario #"<<i<<':'<<'\n';
        double x=(n-1)*2+(m-1)*2;
        printf("%0.2f",x);
        cout<<'\n';
    }

    return 0;
}
