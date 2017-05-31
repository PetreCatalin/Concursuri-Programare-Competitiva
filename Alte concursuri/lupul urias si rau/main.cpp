#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

struct oaie {
    int w,d;
};

const int N=100000;
int n,x,dp,i;
oaie o[N];

inline bool sort_cmp (const oaie &a,const oaie &b) {
     return (a.d > b.d);
};

class set_cmp {
public:
    bool operator() (const oaie &a,const oaie &b) {
        return (a.w > b.w);
};
};

int main() {
    freopen("lupu.in","rt",stdin);
    freopen("lupu.out","wt",stdout);
    scanf("%d %d %d",&n,&x,&dp);

    for (i=0;i<n;++i) {
        scanf("%d %d",&o[i].d,&o[i].w);
        o[i].d =(x-o[i].d)/dp+1;
    }
    sort(o,o+n,sort_cmp);

    long long r = 0;
    multiset<oaie,set_cmp> heap;

    for (int t = o[0].d, i = 0; t; --t) {
        for (; i < n && o[i].d == t; heap.insert(o[i]), ++i);
        if (!heap.empty()) {
            r += (long long)heap.begin()->w;
            heap.erase(heap.begin());
        }
    }

    printf("%lld",r);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

