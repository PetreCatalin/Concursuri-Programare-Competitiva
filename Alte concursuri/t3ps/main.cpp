#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n,i,nr,a[100],poz;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);

    nr=1;
    poz=(n+1)/2+1;
    while (a[poz]==a[(n+1)/2]) {nr++;poz++;}

    poz=(n+1)/2-1;
    while (a[poz]==a[(n+1)/2]) {nr++;poz=poz-1;}

    if (nr>=n/2) cout<<"Da,elementul majoritar este "<<a[(n+1)/2];
    else
    cout<<"Nu exista un element majoritar";

}


