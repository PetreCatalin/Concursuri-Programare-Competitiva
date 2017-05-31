#include <iostream>

using namespace std;

long long n,a,v[200005],maxim,x,i,s,nr;

int main()
{
    cin>>n>>a;
    if (n==1) {cin>>x;cout<<x-1;}
    else {
    for (i=1;i<=n;++i) {
        cin>>v[i];
        if (v[i]>maxim) maxim=v[i];
        s+=v[i];
    }

 /*   if (maxim>=a) maxim=a-n+1;
    else
    maxim=maxim-n+2;

    if (s==a) minim=0;
    else
    minim=s-a; */

    for (i=1;i<=n;++i) {
        if (a==s) cout<<v[i]-1<<' ';
        else {
                nr=s-v[i];
                if (v[i]==a) {
                        if (n-1<=v[i]) cout<<n-1<<" ";
                        else
                        cout<<v[i];
                }
                else
                if (a>=nr){
                        if (a-nr-1>0 &&a-nr-1<=v[i])  cout<<a-nr-1<<" ";
                        else
                        if (a-nr-1<0) cout<<"0 ";
                        else
                        if (a-nr-1>v[i]) cout<<v[i]<<" ";
                }
                else
                cout<<'0'<<" ";
        }
    }
    }

    return 0;
}
