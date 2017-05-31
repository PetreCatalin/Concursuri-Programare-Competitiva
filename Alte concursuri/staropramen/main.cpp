#include <fstream>

using namespace std;

int n,p,i;
int T,r;
int main()
{
    ifstream f("staropramen.in");
    ofstream g("staropramen.out");
    f>>T;
    while (T>0) {
    T--;
    f>>n;
    f.get();
    char c[2*n+2];
    f.getline(c,2*n+2);
    p=2*n-1;
    r=0;
    for(i=2*n-1;i>=0;i-=2)
        {
            if((c[i]+c[i-1]-96+r)>=10)
                c[p--]=(c[i]+c[i-1]-96+r)%10,r=(c[i]+c[i-1]-96+r)/10;
                else
                c[p--]=(c[i]+c[i-1]-96+r)%10,r=0;
        }
    if(r>0)
        c[p--]+=r;
    for(i=p+1;i<=2*n-1;i++)
        g<<(int)c[i];
    g<<'\n';
    }

f.close();
g.close();
return 0;
}
