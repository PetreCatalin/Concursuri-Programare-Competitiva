#include <bits/stdc++.h>

using namespace std;

long long n,nr;

int solve(int n)
{
    if (n%2) return 0;
   int a=n/2/2;
    int b=n%4==0;
    return a-b;
}

int main()
{
    cin>>n;
   cout<<solve(n);

    return 0;
}
