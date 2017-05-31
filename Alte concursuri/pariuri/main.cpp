#include <cstdio>
#include <unordered_map>

using namespace std;

unordered_map <long,long> mmap;
long n,m,x,y,i,j,p;

int main()
{
    freopen("pariuri.in","r",stdin);
    freopen("pariuri.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;++i) {
        scanf("%ld",&m);
        for (j=1;j<=m;++j) {
            scanf("%ld%ld",&x,&y);
            mmap[x]+=y;
        }
    }

    p=mmap.size();
    printf("%ld\n",p);

    for (auto& x: mmap)
           printf("%ld %ld ",x.first,x.second);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
