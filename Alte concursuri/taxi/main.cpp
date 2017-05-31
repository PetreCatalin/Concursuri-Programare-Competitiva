#include <iostream>

using namespace std;

long x,v[5],n,nr,i;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        v[x]++;
    }

    nr=v[4];
    nr=nr+v[2]/2;
    if (v[2]%2==1) v[2]=1;
    else
    v[2]=0;

    if (v[3]<v[1]) {nr=nr+v[3];v[1]=v[1]-v[3];v[3]=0;}
    else
    {
    nr=nr+v[1];v[3]=v[3]-v[1];v[1]=0;
    }

    if (v[1]==0) nr=nr+v[2]+v[3];
    else
    if (v[3]==0) {
        v[1]=v[1]+v[2]*2;
        if (v[1]%4==0) nr=nr+v[1]/4;
        else
        nr=nr+v[1]/4+1;
    }

    cout<<nr;

    return 0;
}
