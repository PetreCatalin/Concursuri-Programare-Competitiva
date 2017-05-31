#include <iostream>

using namespace std;


int n,k,i,v[100],linie[100],maxim[100],j,ok;

int main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>v[i];

    for (i=n;i>=1;i=i-1) {
        ok=0;
        for (j=1;j<=k;j++)
            if (v[i]>maxim[j]) {maxim[j]=v[i];linie[v[i]]=j;ok=1;break;}
        if (ok==0) {cout<<"Nu se poate";break;}
    }

    if (ok==1)
    for (j=1;j<=k;j++) {
        cout<<"Linia "<<j<<": ";
        for (i=1;i<=n;i++)
                if (linie[v[i]]==j) cout<<v[i]<<' ';
            cout<<'\n';
    }

    return 0;
}
