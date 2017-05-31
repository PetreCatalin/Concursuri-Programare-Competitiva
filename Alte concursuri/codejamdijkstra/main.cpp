#include <cstdio>
#include <cstring>

using namespace std;

char s[10005],rez,s1[10005];
long t,k,l,x,i,nrm,ok;

int main()
{
    freopen ("intrare.in","r",stdin);
    freopen ("iesire.out","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;++k) {
        scanf("%d%d\n",&l,&x);
        gets(s);

        strcpy(s1,s);
        for (i=1;i<=x-1;++i)
            strcat(s,s1);

        l=l*x;

        rez='1';
        i=0;ok=0;
        while (1) {
                if (rez=='1') rez=s[i];
                else
                if (rez=='i') {
                        if (s[i]=='i') {rez='1';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='j') rez='k';
                        if (s[i]=='k') {rez='j';if (nrm==0) nrm=1; else nrm=0;}
                }
                else
                if (rez=='j') {
                        if (s[i]=='i') {rez='k';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='j') {rez='1';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='k') rez='i';
                }
                else
                if (rez=='k') {
                        if (s[i]=='i') rez='j';
                        if (s[i]=='j') {rez='i';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='k') {rez='1';if (nrm==0) nrm=1; else nrm=0;}
                }
                ++i;
        if (rez=='i' &&nrm==0) {ok=1;break;}
        else
        if (i==l) break;
        }

        if (ok==1) {
            ok=0;
            rez='1';
             while (1) {
                if (rez=='1') rez=s[i];
                else
                if (rez=='i') {
                        if (s[i]=='i') {rez='1';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='j') rez='k';
                        if (s[i]=='k') {rez='j';if (nrm==0) nrm=1; else nrm=0;}
                }
                else
                if (rez=='j') {
                        if (s[i]=='i') {rez='k';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='j') {rez='1';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='k') rez='i';
                }
                else
                if (rez=='k') {
                        if (s[i]=='i') rez='j';
                        if (s[i]=='j') {rez='i';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='k') {rez='1';if (nrm==0) nrm=1; else nrm=0;}
                }
                ++i;

        if (rez=='j' &&nrm==0) {ok=1;break;}
        else
        if (i==l) break;
            }

            if (ok==1) {
                    ok=0;
                    rez='1';
             while (1) {
                if (rez=='1') rez=s[i];
                else
                if (rez=='i') {
                        if (s[i]=='i') {rez='1';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='j') rez='k';
                        if (s[i]=='k') {rez='j';if (nrm==0) nrm=1; else nrm=0;}
                }
                else
                if (rez=='j') {
                        if (s[i]=='i') {rez='k';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='j') {rez='1';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='k') rez='i';
                }
                else
                if (rez=='k') {
                        if (s[i]=='i') rez='j';
                        if (s[i]=='j') {rez='i';if (nrm==0) nrm=1; else nrm=0;}
                        if (s[i]=='k') {rez='1';if (nrm==0) nrm=1; else nrm=0;}
                }
                ++i;

            if (rez=='k' &&nrm==0) {ok=1;break;}
            else
            if (i==l) break;
            }
        }
        }

        printf("Case #%d: ",k);
        if (ok==1 &&i==l) printf("YES\n");
            else
        printf("NO\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
