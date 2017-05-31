#include <iostream>

using namespace std;

long long a,b,nr,aux,x;

int main()
{
    cin>>a>>b;
    if (b==1) cout<<a;
    else {
    while (b!=0 &&a!=b) {
        a=a-b;
        nr=nr+1;
        if (a<b) {
            aux=a;
            a=b;
            b=aux;
        }
    }

    cout<<nr+1;
    }
    return 0;
}

