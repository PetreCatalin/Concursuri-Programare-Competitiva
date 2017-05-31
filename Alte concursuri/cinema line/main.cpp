#include <iostream>

using namespace std;

long n,i,x,ok,v25,v50;

int main()
{
    cin>>n;
    ok=1;
    for (i=1;i<=n;i++) {
        cin>>x;
        if (x==25) v25++;
        if (x==50) {
                if (v25==0) {ok=0;break;}
                else {
                    v50++;
                    v25=v25-1;
                }
        }
        if (x==100) {
            if (v25==0) {ok=0;break;}
            if (v50==0) {
                if (v25>=3) v25=v25-3;
                else {ok=0;break;}
            }
            else
            if (v50!=0) {v50=v50-1;v25=v25-1;}
        }
    }

    if (ok==1) cout<<"YES";
    else
    cout<<"NO";
    return 0;
}
