#include <iostream>
#include <cstring>

using namespace std;

int i,n;
char x[105];

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        if (strlen(x)<=10) cout<<x;
            else
            {
                cout<<x[0];
                cout<<strlen(x)-2;
                cout<<x[strlen(x)-1];
            }
        cout<<'\n';
    }
    return 0;
}
