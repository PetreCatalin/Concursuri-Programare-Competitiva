/*// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

using namespace std;

long n,m,x,i,nr,poz,ap[1000005];
vector <long> v;

int main () {

    cin>>n;
    cin>>x;
    v.push_back(x);
    for (i=2;i<=n;++i) {
            cin>>x;
            v.push_back(v[i-2]+x);
    }

    cin>>m;
    for (i=1;i<=m;++i) {
            cin>>x;
            if (ap[x]!=0) cout<<ap[x]<<'\n';
            else {
            vector<long>::iterator it;
            it = find (v.begin(), v.end(), x);

            if (it!=v.end()) {
                    cout<<(it-v.begin()+1)<<'\n';
                    ap[x]=it-v.begin()+1;
            }

            else {
            vector<long>::iterator up;
            up= std::upper_bound (v.begin(), v.end(), x);
            cout<<(up - v.begin()+1)<<'\n';
            ap[x]=up-v.begin()+1;
            }
            }
    }

  return 0;
} */

#include <iostream>

using namespace std;

long n,m,x,i,nr,poz,ap[1000005],a,j;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
            cin>>x;
            for (j=a+1;j<=a+x;++j)
                ap[j]=i;
            a+=x;
    }
    cin>>m;
    for (i=1;i<=m;++i) {
            cin>>x;
            cout<<ap[x]<<'\n';
    }
}
