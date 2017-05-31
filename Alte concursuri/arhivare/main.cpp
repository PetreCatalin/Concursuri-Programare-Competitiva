#include <fstream>
#include <cstring>

using namespace std;

typedef struct {
       char s[100];
}nume;

nume a[2000];
int i,nr,x,p,u,j;
bool ok,ok2;
char st[1000],c[1000];

int main()
{
       ifstream f("arhivare.in");
       ofstream g("arhivare.out");
       gets(st);
       x=0;
       p=0;
       for (i=1;i<=strlen(st)-1;i++) {
              if ((st[i]<='z' && st[i]>='a') || (st[i]<='Z' && st[i]>='A')) ok=true;
              else ok=false;
              if (ok==false && ((st[i-1]<='z' && st[i-1]>='a') || (st[i-1]<='Z' && st[i-1]>='A')))
                     {u=i-1;
                     ok2=true;
                     strncpy(c,st+p,u-p+1);
                     for (j=1;j<=x;j++) {
                            nr=strcmp(a[j].s,c);
                            if (nr==0) ok2=false;
                            break;}
                     if (ok2==true) {x++;strcpy(a[x].s,c);g<<a[x].s<<st[i];}
                     if (ok2==false) {g<<j<<st[i];}
                     }
              if (ok=false) p=i+1;
       }
       f.close();
       g.close();
    return 0;
}
