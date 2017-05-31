#include <iostream>

using namespace std;

char s;
long i,n,v[30],nr;

int main()
{
    cin>>n;
    for (i=0;i<=2*n-3;++i) {
        cin>>s;
        if (s>='a' &&s<='z')
            ++v[s-'a'+1];
        else {
            if (v[s-'A'+1]==0) ++nr;
            else
                --v[s-'A'+1];
        }
    }

    cout<<nr;

    return 0;
}
