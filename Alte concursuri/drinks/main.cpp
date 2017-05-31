#include <iostream>

using namespace std;

float m,s;
int n,i,x;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        s=s+x;
    }

    m=s/n;

    cout<<m;
    return 0;
}
