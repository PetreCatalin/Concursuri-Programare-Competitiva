#include <iostream>

using namespace std;

long long n,nr,i,nr1,v[10],j,x;

int main()
{
    cin>>n;
    if (n<102) cout<<n;
    else {
        nr=101;
        for (i=110;i<=n;i++) {
            x=i;nr1=0;
            for (j=0;j<=9;j++)
                if (v[j]!=0) v[j]=0;
            while (x>0) {
                if (v[x%10]==0) {v[x%10]=1;nr1++;}
                if (nr1>2) break;
                x=x/10;
            }
            if (nr1<=2) nr++;
        }
    cout<<nr;
    }

    return 0;
}
