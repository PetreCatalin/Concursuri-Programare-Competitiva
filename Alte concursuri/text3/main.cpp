#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct
{
    char s[25];
}nume;


nume a[20003];
char s[205];
long int nr,i,v[20003],maxim,poz,v2[20003],j,b[20003];

int main()
{
    freopen ("text3.in","r",stdin);
    freopen ("text3.out","w",stdout);
    while (!feof(stdin))
    {
        gets(s);
        char *p=strtok(s," ");
        while (p) {
            nr++;
            strcpy(a[nr].s,p);
            p=strtok(NULL," ");
        }
    }

    printf("%d\n",nr-1);
    --nr;

    v[1]=1;v2[1]=0;
    for (i=2;i<=nr;i++) {
        maxim=0;poz=0;
        for (j=1;j<=i-1;j++)
            if (a[i].s[0]==a[j].s[strlen(a[j].s)-1] &&v[j]>maxim) {maxim=v[j];poz=j;}
        v[i]=maxim+1;
        v2[i]=poz;
    }

    maxim=0;
    for (i=1;i<=nr;i++)
        if (v[i]>maxim) {maxim=v[i];poz=i;}

    printf("%d\n",nr-maxim);
    nr=0;
    while (poz!=0) {
        nr++;
        b[nr]=poz;
        poz=v2[poz];
    }

    for (i=nr;i>=1;--i)
    printf("%s\n",a[b[i]].s);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
