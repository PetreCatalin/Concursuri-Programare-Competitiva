#include <cstdio>
#include <cstring>

using namespace std;

char s[100005];
long int i,j,maxim,k,nr,numar,v1[100002],v2[100002],minim,x;

int main()
{
    freopen ("blis.in","r",stdin);
    freopen ("blis.out","w",stdout);
    scanf("%d\n",&k);
    gets(s);
    nr=strlen(s);
    if (k>=nr) {
        numar=0;
        for (i=0;i<=nr-1;i++)
        numar=numar*2+s[i]-'0';
        printf("%d\n",numar);
    }
    else
    {
        maxim=0;
        for (i=0;i<=nr-k;i++) {
           numar=0;
           for (j=i;j<=i+k-1;j++)
           numar=numar*2+s[j]-'0';
            if (numar>maxim) maxim=numar;
        }
        printf("%d\n",maxim);
    }

    v1[0]=1;
    if (s[0]=='0') v2[0]=0;
    else v2[0]=1;

    for (i=1;i<=nr;i++) {
        if (i-k+1>0) minim=i-k+1;
        else
        minim=0;
        for (j=minim;j<=i;j++) {
            numar=0;
            for (x=j;x<=i;x++)
            numar=numar*2+s[x]-'0';
        maxim=0;
        for (x=j-1;x>=0;x--)
            if (v2[x]<numar &&v1[x]>maxim) maxim=v1[x];
        if (maxim+1>v1[i]) {v1[i]=maxim+1;v2[i]=numar;}
        if (maxim+1==v1[i] &&numar<v2[i]) v2[i]=numar;
        }
    }

    maxim=0;
    for (i=0;i<=nr;i++)
    if (v1[i]>maxim) maxim=v1[i];

    printf("%d",maxim);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
