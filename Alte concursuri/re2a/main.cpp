#include <bits/stdc++.h>

using namespace std;

long long i,ok,j,x,nr;
char s[300005],a[300005],b[300005];

int main()
{
    cin>>s;
    for (i=0;i<strlen(s);++i)
        if ((s[i]==';' ||s[i]==',') &&(s[i+1]==';' ||s[i+1]==',')) {
                for (j=strlen(s);j>=i+2;--j) s[j]=s[j-1];
                s[i+1]=' ';
        }

    if (s[strlen(s)-1]==',' || s[strlen(s)-1]==';') strcat(s," ");

    x=2;
    char * pch;
    pch=strtok(s,",;");
    while (pch!=NULL) {
        if (strlen(pch)==0)
                strcat(b,",");
        else
        if (strlen(pch)==1 &&pch[0]==' ') {
        if (nr>0) {strcat(b,",");x=1;}
        ++nr;
        }
        else {
        ok=1;
        if (pch[0]=='0' &&strlen(pch)>1) ok=0;
        if (ok==1) {
        for (i=0;i<strlen(pch);++i)
        if (pch[i]<'0' ||pch[i]>'9') {ok=0;break;}
        }

        if (ok==1) {
            if (strlen(a)!=0) strcat(a,",");
            strcat(a,pch);
        }
        else {
        if (x==1) strcat(b,",");
        x=2;
        if (pch[0]!=' ')
        strcat(b,pch);
        }
        }
        pch=strtok(NULL,",;");
    }

    if (strlen(a)==0) cout<<'-';
    else {
    cout<<'"';
    cout<<a;
    cout<<'"';
    }
    cout<<'\n';

    if (strlen(b)==0) cout<<'-';
    else {
    cout<<'"';
    cout<<b;
    cout<<'"';
    }
    return 0;
}
