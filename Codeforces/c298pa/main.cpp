#include <iostream>

using namespace std;

long n,i,nr;

int main()
{
    cin>>n;
    if (n==1) cout<<"1"<<"\n"<<"1";
    if (n==2) cout<<"1"<<"\n"<<"1";
    if (n==3) cout<<"2"<<"\n"<<"1 3";
    if (n>=4) {
            cout<<n<<"\n";
            nr=n/2;
            for (i=nr;i>=1;--i)
                cout<<i<<" "<<i+nr<<" ";
            if (n%2==1) cout<<n;
    }

    return 0;
}
