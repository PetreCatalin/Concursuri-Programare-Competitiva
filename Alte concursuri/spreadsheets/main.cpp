#include <iostream>
#include <cstring>

using namespace std;

char s[20],s1[20];
long n,i,x,j,col,lin,nr,k,t,initial,total;

int main()
{
    cin>>n;
    for (t=1;t<=n;t++) {
        cin>>s;
        col=0;lin=0;
        if (s[0]=='R') {
            x=1;
            while (s[x]!='C') x++;
            for (j=x+1;j<=strlen(s)-1;j++)
                col=col*10+s[j]-'0';
            for (j=1;j<=x-1;j++)
                lin=lin*10+s[j]-'0';

            x=0;
            while (col>26) {
                k=1;total=0;
            while (total+k*26<col) {k=k*26;total=total+k;}
                initial=k;
                nr=0;
                while (total+initial<col) {nr++;total=total+initial;}
                s1[x]='A'+nr;
                x++;
                col=col-k;
            }
            s1[x]='A'+col-1;
            for (i=0;i<=x;i++)
                cout<<s1[i];
            cout<<lin<<'\n';
        }

        else {
            x=0;
            while (s[x]>='A' &&s[x]<='Z') x++;
            for (i=x;i<=strlen(s)-1;i++) lin=lin*10+s[i]-'0';
            k=1;
            for (i=x-1;i>=0;i=i-1) {
                col=col+(s[i]-'A'+1)*k;
                k=k*26;
            }
            cout<<'R'<<lin<<'C'<<col<<'\n';
        }
    }

    return 0;
}
