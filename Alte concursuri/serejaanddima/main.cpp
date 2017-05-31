#include <iostream>

using namespace std;

long n,v[1005],i,st,dr,s1,s2,nr,maxim;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>v[i];
    st=1;dr=n;

    while (st<=dr) {
        if (v[st]>v[dr]) {maxim=v[st];st++;}
            else
        {
            maxim=v[dr];dr=dr-1;
        }
        nr++;
        if (nr%2==1) s1=s1+maxim;
        else
        s2=s2+maxim;
    }

    cout<<s1<<' '<<s2;

    return 0;
}
