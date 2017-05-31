#include <iostream>

using namespace std;

long long n,l,r,x,j,i,nr,poz,maxim,put;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>l>>r;
        put=1;
        while (put*2<=r+1) put<<=1;
        if (l<=put-1 &&put<=r) cout<<put-1<<'\n';
        else {
        maxim=0;
        for (j=l;j<=r;j++) {
            x=j;
            nr=0;
            while (x!=0) {
                if (x%2==1) nr++;
                x=x/2;
            }
            if (nr>maxim) {maxim=nr;poz=j;}
        }
        cout<<poz<<'\n';
        }
    }

    return 0;
}
