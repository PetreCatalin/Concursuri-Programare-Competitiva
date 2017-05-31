#include <iostream>

using namespace std;

int n,i,minim,i1,i2,j,nr,maxim;
char s1[200005],s2[200005];

int main()
{
    cin>>n;
    cin>>s1;
    cin>>s2;
    for (i=0;i<n;++i)
        if (s1[i]!=s2[i]) ++minim;

    if (minim<=1) {
        cout<<minim<<'\n';
        cout<<"-1"<<" "<<"-1";
    }
    else {

    maxim=0;
    for (i=0;i<n-1;++i) {
        if (s1[i]!=s2[i]) {
        for (j=i+1;j<n;++j) {
            nr=0;
            if (s1[j]!=s2[j]) {
                if (s1[i]==s2[j]) ++nr;
                if (s1[j]==s2[i]) ++nr;
                if (nr>maxim) {
                    i1=i;
                    i2=j;
                    maxim=nr;
                }
            }
            if (maxim==2) break;
            }
        }
        if (maxim==2) break;
        }

    if (maxim==0) {
        cout<<minim<<"\n";
        cout<<"-1"<<" "<<"-1";
    }
    else {
        cout<<minim-maxim<<"\n";
        cout<<i1+1<<" "<<i2+1;
    }
    }

    return 0;
}
