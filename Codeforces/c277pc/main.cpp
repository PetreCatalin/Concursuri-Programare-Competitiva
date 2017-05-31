#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

long long n,p,mij,nr,minim,i,min1,min2,mij1,mij2,nr1,k;
char s[100005];

int main()
{
    cin>>n>>p;
    cin>>s;
    mij=n/2-1;

    --p;k=n;

    if (n%2==0) {
        mij1=mij;
        mij2=mij+1;
    }
    else
    {
        mij1=mij;
        mij2=mij+2;
    }

    int ok=1;
    for (i=0;i<=mij;++i)
        if (s[i]!=s[k-i-1]) {ok=0;break;}

    if (ok==1) cout<<'0';
    else {
    while (s[mij1]==s[mij2]) {--mij1;++mij2;}

    nr1=0;--n;
    while (s[nr1]==s[n-nr1]) ++nr1;
    n=n-nr1;

    minim=abs(mij1-p);
    if (abs(p-nr1)<minim) minim=abs(p-nr1);
    if (abs(p-mij2)<minim) minim=abs(p-mij2);
    if (abs(n-p)<minim) minim=abs(n-p);

        nr+=minim;
        --nr;

    for (i=nr1;i<=mij1;++i) {
        min1=abs(s[i]-s[k-i-1]);
        min2=26-min1;
        if (min1<min2) nr+=min1+1;
        else
        nr+=min2+1;
    }

    cout<<nr;
    }

    return 0;
}
