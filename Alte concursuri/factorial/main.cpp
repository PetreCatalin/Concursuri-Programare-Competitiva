#include <iostream>

using namespace std;

int n,nr,i,p;

int main()
{
    cin>>n;
    nr=1; p=10;
    for (i=2;i<=n;i++) {
        if (i%10!=0)
            nr=nr*(i%10);
        else
            nr=nr*(i/10);

        if (nr%10==0) nr=nr/p;
        else {
        if (nr>=100) p=100;
        if (nr>=1000) p=1000;
        nr=nr%p;
        }
    }

    cout<<nr;
    return 0;
}
