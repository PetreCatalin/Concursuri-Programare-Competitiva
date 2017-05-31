#include <iostream>
#include <cmath>

using namespace std;

long long v1,v2,t,d,nr,s,i,x,aux;

int main()
{
    cin>>v1>>v2>>t>>d;
    if (d==0) cout<<v1*t;
    else {
    nr=2;
    if (t%2==1) x=1;
    else
    x=0;
    s+=v1;
    s+=v2;
    if (abs(v1-v2)<(t-nr-x)*d)
    while(nr<t) {
            v1+=d;
            v2+=d;
            s+=v1;
            ++nr;
            if (t!=nr) {
            s+=v2;
            ++nr;
            }
            if (abs(v1-v2)>=(t-nr-x)*d) break;
    }

    if (v2>v1) {
            aux=v2;
            v2=v1;
            v1=v2;
    }
    for (i=nr+1;i<=t;++i) {
        v2+=d;
        s+=v2;
    }

    cout<<s;
    }

    return 0;
}
