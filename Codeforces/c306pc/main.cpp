#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int nr,i,j,k,n,ok;
char s[105];

int main()
{
    ok=0;
    gets(s);
    nr=strlen(s)-1;
    if (nr==0) {
            n=s[0]-'0';
            if (n%8==0) {
                cout<<"YES\n";
                cout<<n;;
           }
           else
            cout<<"NO";
    }

    if (nr==1) {
            n=(s[0]-'0')*10+s[1]-'0';
             if (n%8==0) {
                cout<<"YES\n";
                cout<<n;;
           }
           else {
                n=s[0]-'0';
                 if (n%8==0) {
                cout<<"YES\n";
                cout<<n;;
                }
                else {
                      n=s[1]-'0';
                        if (n%8==0) {
                        cout<<"YES\n";
                        cout<<n;;
                        }
                else
                    cout<<"NO";
                } n=s[0]-'0';
                 if (n%8==0) {
                cout<<"YES\n";
                cout<<n;;
                }
           }
    }

    if (nr>=2) {
    for (i=0;i<=nr-2;++i) {
    if (ok==1) break;
    n=s[i]-'0';
     if (n%8==0) {
                            cout<<"YES"<<'\n';
                            cout<<n;
                            ok=1;
                            break;
                    }
        for (j=i+1;j<=nr-1;++j) {
            if (ok==1) break;
            n=n*10+s[j]-'0';
             if (n%8==0) {
                            cout<<"YES"<<'\n';
                            cout<<n;
                            ok=1;
                            break;
                    }
            for (k=j+1;k<=nr;++k) {
                    n=n*10+s[k]-'0';
                    if (n%8==0) {
                            cout<<"YES"<<'\n';
                            cout<<n;
                            ok=1;
                            break;
                    }
            }
        }
    }

    if (ok==0) cout<<"NO";
    }

    return 0;
}
