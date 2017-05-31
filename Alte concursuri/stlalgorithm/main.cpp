#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int>:: iterator it;
int n,x,i,v[100];

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>v[x];

    it=min_element(v+2,v+5);
    cout<<*it<<' ';
    it=max_element(v,v+7);
    cout<<*it;

    return 0;
}
