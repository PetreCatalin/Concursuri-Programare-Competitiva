#include <iostream>

using namespace std;

long n,nr,v[12];

int main()
{
    cin>>n;
    v[0]=2;
    v[1]=7;
    v[2]=2;
    v[3]=3;
    v[4]=3;
    v[5]=4;
    v[6]=2;
    v[7]=5;
    v[8]=1;
    v[9]=2;
    nr=v[n/10]*v[n%10];
    cout<<nr;
    return 0;
}
