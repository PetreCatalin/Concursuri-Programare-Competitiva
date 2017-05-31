#include <cstring>
#include <cstdio>

using namespace std;

char s[100];
int i,n,nr;

int main()
{
    freopen("nrcuv.in","r",stdin);
    freopen("nrcuv.out","w",stdout);
    gets(s);
    nr=0;
    strcat(s," ");
    n=strlen(s);
    for (i=0;i<=n-2;i++)
        if (s[i]!=' ' && s[i+1]==' ')
        nr++;
    printf("%d\n",nr);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
