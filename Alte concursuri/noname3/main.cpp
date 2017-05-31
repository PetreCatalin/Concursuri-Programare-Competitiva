#include <iostream>

using namespace std;

long long n,s;

int main()
{
    ifstream f("noname3.in");
    ofstream g("noname3.out");
    f>>n>>s;
    if (s%n!=0) {
        x=s/n;
        while (nr<n/2-1)
            v[++nr]=x-(n/2-1)-nr+1;
        v[++nr]=x;
        while (nr<n)
            v[++nr]=v[nr-1]+1;
    }




    f.close();
    g.close();
    return 0;
}
