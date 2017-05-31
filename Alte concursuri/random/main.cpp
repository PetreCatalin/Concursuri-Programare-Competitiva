#include <bits/stdc++.h>

using namespace std;

long n;

int main()
{
    ifstream f("random.in");
    ofstream g("random.out");
    f>>n;
    if (n==1982) g<<"Robert Tarjan";
    if (n==1986) g<<"Leslie Valiant";
    if (n==1990) g<<"Alexander Razborov";
    if (n==1994) g<<"Avi Wigderson";
    if (n==1998) g<<"Peter Shor";
    if (n==2002) g<<"Madhu Sudan";
    if (n==2006) g<<"Jon Kleinberg";
    if (n==2010) g<<"Daniel Spielman";
    if (n==2014) g<<"Subhash Khot";
    f.close();
    g.close();
    return 0;
}
