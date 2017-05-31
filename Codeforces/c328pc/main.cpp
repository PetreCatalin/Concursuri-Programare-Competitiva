#include <bits/stdc++.h>

using namespace std;

long long t,w,b,i,rez,nr1,nr2;

int main()
{
    cin>>t>>w>>b;
    if (w==1 &&b==1) ++rez;
    if (w>1 &&b>1) ++rez;
    for (i=2;i<=t;++i) {
        if (w>i &&b>i) ++rez;
        else
        if (w%i==0 &&b%i==0) ++rez;
        else
            {
                nr1=i;
                while (nr1%w!=0) --nr1;
                nr2=i;
                while (nr2%b!=0) --nr2;
                if (nr1==nr2) ++rez;
            }

    return 0;
}
