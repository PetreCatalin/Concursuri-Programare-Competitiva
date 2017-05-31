#include<cstdio>
#include<cstring>

using namespace std;

int i,n,j,k,maxim,nr,x,nr1;
char s[100],p[100],a[100]="",f[100];
bool ok;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    gets(s);
    n=strlen(s)-1;
    maxim=0;
    for (i=0;i<=n-1;i++)
        for (j=i;j<=n;j++) {
                nr1=strlen(p)-1;
                for (x=0;x<=nr1;x++)
                p[x]=NULL;
                strncpy(p,s+i,j+1);
                ok=true;
                nr=strlen(p);
                for (x=0;x<=nr/2-1;x++) {
                    if (p[x]!=p[nr-x-1]) ok=false;
                    if (ok==false) break;
                }
                if (ok==true) if (nr>maxim) {maxim=nr;nr1=strlen(f)-1;for (x=0;x<=nr1;x++) f[x]=NULL;strcpy(f,p);}
            }
    printf("%s",f);
    fclose(stdin);
    fclose(stdout);
return 0;
}






