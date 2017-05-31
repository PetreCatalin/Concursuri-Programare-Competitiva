#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

char s[1030];
long i,ok,v[10150],nr;

int main()
{
   freopen ("convertor.in","r",stdin);
   freopen ("convertor.out","w",stdout);
   while (!feof(stdin)) {
       gets(s);
       if (s[0]!='}' &&s[0]!='[') {
           if (ok==0) ok=1;
           for (i=2;i<=strlen(s)-1;++i) {
                if (s[i]=='"') {v[++nr]=i+3;break;}
                printf("%c",s[i]);
            }
            printf(",");
       }
       else
           if (ok==1) printf("\n");
    }

   fclose(stdin);
   fclose(stdout);
    return 0;
}
