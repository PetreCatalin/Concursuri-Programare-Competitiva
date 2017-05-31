#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin>>h1>>a1>>d1;
    cin>>h2>>a2>>d2;
    cin>>c1>>c2>>c3;
    while (h2>0) {
        h1=h1-max(0,a2-d1);
        h2=h2-max(0,a1-d2);
    }

    if (h1==0 &&h2!=0) {


    return 0;
}
