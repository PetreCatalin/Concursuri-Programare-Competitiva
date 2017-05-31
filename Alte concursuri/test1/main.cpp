#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

double dist,nr,d,i;
#define EPS 0.000001

int main()
{
    nr=120.000000;
    i=0;
    d=120.000000;
    while (i<60) {
        i+=EPS;
        dist+=nr-i;
        if (i-floor(i)<EPS) {
            dist=dist/1000000;
            d=d-dist/60;
            dist=0;
        }
    }

    printf("%0.5f",d);

    return 0;
}
