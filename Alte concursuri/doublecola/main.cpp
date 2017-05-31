#include <iostream>
#include <cstring>

using namespace std;

long long n,inc,fin,p,nr,x,ok;
char s[6][10];

int main()
{
    strcpy(s[1],"Sheldon");
    strcpy(s[2],"Leonard");
    strcpy(s[3],"Penny");
    strcpy(s[4],"Rajesh");
    strcpy(s[5],"Howard");

    cin>>n;p=1;
    if (n<=5) cout<<s[n];
    else {
        fin=5;
        while (fin<n) {
            inc=fin+1;
            p=p*2;
            fin=fin+p*5;
        }

        nr=0; x=inc;
        ok=0;
        while (ok==0) {
            nr++;
            if (inc>n) {cout<<s[nr-1];ok=1;break;}
            else
            if (inc==n) {cout<<s[nr];ok=1;break;}
            inc=inc+(fin-x+1)/5;
        }
    }

    return 0;
}
