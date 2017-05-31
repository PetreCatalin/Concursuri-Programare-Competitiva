#include <iostream>

using namespace std;

int n,m,lung,nr;

int main()
{
    cin>>m>>n;
    lung=m/2;
    nr=lung*n;
    if (m%2==1) nr=nr+n/2;
    cout<<nr;
    return 0;
}
